/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _RAYINTERSECTIONITERATOR_H
#define _RAYINTERSECTIONITERATOR_H

#include "../g3dlite/G3D/CollisionDetection.h"
#include "../g3dlite/G3D/AABox.h"

#include "NodeValueAccess.h"

using namespace G3D;

/*
 * The Class is mainly taken from G3D/AABSPTree.h but modified to be able to use our internal data structure.
 * This is an iterator that helps us analysing the BSP-Trees.
 * The collision detection is modified to return true, if we are inside an object.
 */

namespace VMAP
{

	class MyCollisionDetection
	{
		public:
			static bool collisionLocationForMovingPointFixedAABox(
				const Vector3&  origin,
				const Vector3&  dir,
				const AABox&    box,
				Vector3&        location,
				bool&           Inside,
				Vector3&        normal)
			{

				// Integer representation of a floating-point value.
			#define IR(x)   ((uint32&)x)

				Inside = true;
				const Vector3& MinB = box.low();
				const Vector3& MaxB = box.high();
				Vector3 MaxT(-1.0f, -1.0f, -1.0f);

				// Find candidate planes.
				for (int i = 0; i < 3; ++i)
				{
					if (origin[i] < MinB[i])
					{
						location[i] = MinB[i];
						Inside = false;

						// Calculate T distances to candidate planes
						if (IR(dir[i]))
						{
							MaxT[i] = (MinB[i] - origin[i]) / dir[i];
						}
					}
					else if (origin[i] > MaxB[i])
					{
						location[i] = MaxB[i];
						Inside = false;

						// Calculate T distances to candidate planes
						if (IR(dir[i]))
						{
							MaxT[i] = (MaxB[i] - origin[i]) / dir[i];
						}
					}
				}

				if (Inside)
				{
					// definite hit
					location = origin;
					return true;
				}

				// Get largest of the maxT's for final choice of intersection
				int WhichPlane = 0;
				if (MaxT[1] > MaxT[WhichPlane])
				{
					WhichPlane = 1;
				}

				if (MaxT[2] > MaxT[WhichPlane])
				{
					WhichPlane = 2;
				}

				// Check final candidate actually inside box
				if (IR(MaxT[WhichPlane]) & 0x80000000)
				{
					// Miss the box
					return false;
				}

				for (int i = 0; i < 3; ++i)
				{
					if (i != WhichPlane)
					{
						location[i] = origin[i] + MaxT[WhichPlane] * dir[i];
						if ((location[i] < MinB[i]) ||
							(location[i] > MaxB[i]))
						{
							// On this plane we're outside the box extents, so
							// we miss the box
							return false;
						}
					}
				}

				// Choose the normal to be the plane normal facing into the ray
				normal = Vector3::zero();
				normal[WhichPlane] = (dir[WhichPlane] > 0) ? -1.0 : 1.0;

				return true;

			#undef IR
			}
	};

	#ifdef _DEBUG_VMAPS
	extern Vector3 p1,p2,p3,p4,p5,p6,p7;
	extern Array<AABox>gBoxArray;
	extern int gCount1, gCount2, gCount3, gCount4;
	extern bool myfound;
	#endif

	template<class TNode, class TValue>  class RayIntersectionIterator
	{
		private:

			/** The stack frame contains all the info needed to resume
			computation for the RayIntersectionIterator */

			struct StackFrame
			{
				const TNode* node;

				/** the total checking bounds for this frame */
				float minTime;

				/** minTime^2 */
				float minTime2;
				float maxTime;

				/** what we're checking right now, either from minTime to the
				split, or from the split to maxTime (more or less...
				there are edge cases) */
				float startTime;
				float endTime;

				/** endTime^2 */
				float endTime2;

				int nextChild;

				/** current index into node's valueArray */
				int valIndex;

				/** cache intersection values when they're checked on the preSide,
				split so they don't need to be checked again after the split. */
				Array<float> intersectionCache;

				NodeValueAccess<TNode, TValue>* iNodeValueAccess;

				void init(NodeValueAccess<TNode, TValue>* pNodeValueAccess, const TNode* inNode, const Ray& ray, float inMinTime, float inMaxTime)
				{
					node	= inNode;
					minTime  = inMinTime;
					maxTime  = inMaxTime;
					minTime2 = square(minTime);
					valIndex = -1;

					iNodeValueAccess = pNodeValueAccess;
					intersectionCache.resize(node->getNValues());

					if (node->getChild(iNodeValueAccess->getNodePtr(),0) == NULL && node->getChild(iNodeValueAccess->getNodePtr(), 1) == NULL)
					{
						startTime = minTime;
						endTime   = maxTime;
						endTime2  = square(maxTime);
						nextChild = -1;
						return;
					}

					Vector3::Axis splitAxis	= node->getSplitAxis();
					double		splitLocation = node->getSplitLocation();

					// this is the time along the ray until the split.
					// could be negative if the split is behind.
					double splitTime =
						(splitLocation - ray.origin[splitAxis]) /
						ray.direction[splitAxis];

					// If splitTime <= minTime we'll never reach the
					// split, so set it to inf so as not to confuse endTime.
					// It will be noted below that when splitTime is inf
					// only one of this node's children will be searched
					// (the pre child). Therefore it is critical that
					// the correct child is gone too.
					if (splitTime <= minTime)
					{
						splitTime = inf();
					}

					startTime = minTime;
					endTime   = std::min((double)maxTime, splitTime);
					endTime2  = square(endTime);

					double rayLocation = ray.origin[splitAxis] +
						ray.direction[splitAxis] * minTime;

					if (rayLocation == splitLocation)
					{
						// We're right on the split. Look ahead.
						rayLocation = ray.origin[splitAxis] +
							ray.direction[splitAxis] * maxTime;
					}

					if (rayLocation == splitLocation)
					{
						// right on the split, looking exactly along
						// it, so consider no children.
						nextChild = -1;
					}
					else if(rayLocation <= splitLocation)
					{
						nextChild = 0;
					}
					else
					{
						nextChild = 1;
					}
				}
			};

		public:
			/* A minimum bound on the distance to the intersection. */
			double minDistance;

			/* A maximum bound on the distance to the intersection. */
			double maxDistance;

			/* Counts how many bounding box intersection tests have been made so
			far. */
			int debugCounter;

		private:
			Ray					ray;
			Ray					reverseRay;
			bool				isEnd;

			Array<StackFrame>	stack;
			int					stackLength;
			int					stackIndex;
			int					breakFrameIndex;
			bool				skipAABoxTests;
			NodeValueAccess<TNode, TValue> iNodeValueAccess;
			double				boxMaxDist2;
			double				boxMaxDist;

		public:
			RayIntersectionIterator(const NodeValueAccess<TNode, TValue> pNodeValueAccess, const Ray& r, const TNode* root,  double pMaxTime, bool skip)
				: minDistance(0), maxDistance(inf()), debugCounter(0),
				ray(r), isEnd(root == NULL),
				stackLength(20), stackIndex(0), breakFrameIndex(-1),
				skipAABoxTests(skip)
			{
				iNodeValueAccess = pNodeValueAccess;
				stack.resize(stackLength);
				stack[stackIndex].init(&iNodeValueAccess, root, ray, 0, inf());
				//stack[stackIndex].init(&iNodeValueAccess, root, ray, 0, pMaxTime);
				boxMaxDist2 = pMaxTime*pMaxTime;
				boxMaxDist = pMaxTime;
				++(*this);
			}

			/* public so we can have empty ones */
			RayIntersectionIterator() : isEnd(true) {}

			inline bool operator!=(const RayIntersectionIterator& other) const
			{
				return ! (*this == other);
			}

			/* Compares two iterators, but will only return true if both are at the end. */
			bool operator==(const RayIntersectionIterator& other) const
			{
				if (isEnd)
				{
					return other.isEnd;
				}

				return false;
			}

			/*
			Marks the node where the most recent intersection occurred. If
			the iterator exhausts this node it will stop and set itself to
			the end iterator.

			Use this after you find a true intersection to stop the iterator
			from searching more than necessary.
			<B>Beta API-- subject to change</B>
			*/
			// In theory this method could be smarter: the caller could pass in
			// the distance of the actual collision and the iterator would keep
			// itself from checking nodes or boxes beyond that distance.
			void markBreakNode()
			{
				breakFrameIndex = stackIndex;
			}

			/*
			Clears the break node. Can be used before or after the iterator
			stops from a break.
			<B>Beta API-- subject to change</B>
			*/
			void clearBreakNode()
			{
				if (breakFrameIndex < 0)
				{
					return;
				}

				if (isEnd && stackIndex >= 0)
				{
					isEnd = false;
				}

				breakFrameIndex = -1;
			}

			RayIntersectionIterator& operator++()
			{
				alwaysAssertM(!isEnd, "Can't increment the end element of an iterator");

				StackFrame* s = &stack[stackIndex];

				// leave the loop if:
				//	end is reached (ie: stack is empty)
				//	found an intersection

				while (true)
				{
					++s->valIndex;

					if (s->valIndex >= s->node->getNValues())
					{
						// This node is exhausted, look at its
						// children.

						const TNode* child = (s->nextChild >= 0) ?
							s->node->getChild(iNodeValueAccess.getNodePtr() ,s->nextChild) : NULL;
						double childStartTime = s->startTime;
						double childEndTime   = s->endTime;

						if (s->endTime < s->maxTime)
						{
							// we can come back to this frame,
							// so reset it
							s->valIndex  = -1;
							s->startTime = s->endTime;
							s->endTime   = s->maxTime;
							s->endTime2  = square(s->maxTime);
							s->nextChild = (s->nextChild >= 0) ? (1 - s->nextChild) : -1;

							// this could be changed somehow,
							// since Array already does the
							// power-of-two growth stuff
							if (stackIndex == stackLength)
							{
								stackLength *= 2;
								stack.resize(stackLength);
							}
						}
						else
						{
							// tail-recursion: we won't come
							// back to this frame, so we can
							// remove it.

							if (stackIndex == breakFrameIndex)
							{
								// This will be the case if the
								// break frame is set on a node, but
								// the node is exhausted so it won't
								// be put on the stack. Here we
								// decrement the break frame so that
								// the break occurs when the current
								// frame's parent is resumed.
								--breakFrameIndex;
							}

							--stackIndex;
						}

						// There could have been a resize on the array, so
						// do not use s (pointer into the array)!

						if (child != NULL)
						{
							++stackIndex;
							stack[stackIndex].init(&iNodeValueAccess, child, ray, childStartTime, childEndTime);
						}

						if ((stackIndex < 0) || (stackIndex == breakFrameIndex))
						{
							isEnd = true;
							break;
						}

						s = &stack[stackIndex];
						continue;
					}

					if (skipAABoxTests)
					{
						// No AABox test-- return everything
						minDistance = s->startTime;
						maxDistance = s->endTime;
						break;
					}
					else
					{
						double t2;
						// this can be an exact equals because the two
						// variables are initialized to the same thing
						if (s->startTime == s->minTime)
						{
							bool insiteOk;
							Vector3 mynormal;
							Vector3 location;
							TValue currValue = iNodeValueAccess.getValue(s->valIndex+ s->node->getStartPosition());

						#ifdef _DEBUG_VMAPS
							if(gCount2 >= gCount1)
							{
								AABox testbox = currValue.getAABoxBounds();
								gBoxArray.append(AABox(testbox.low() + currValue.getBasePosition(), testbox.high() + currValue.getBasePosition()));
							}
							++gCount2;
						#endif

							if (

								MyCollisionDetection::collisionLocationForMovingPointFixedAABox(
								ray.origin, ray.direction,
								currValue.getAABoxBounds(),
								location,insiteOk, mynormal))
							{
								// Optimization: store t-squared
								t2 = (location - ray.origin).squaredLength();
							}
							else
							{
								t2 = inf();
							}
							if(t2 > boxMaxDist2)
								t2=inf();				// too far off
							s->intersectionCache[s->valIndex] = t2;
							++debugCounter;
						}
						else
						{
							t2 = s->intersectionCache[s->valIndex];
						}

						// use minTime here because intersection may be
						// detected pre-split, but be valid post-split, too.
						if ((t2 >= s->minTime2) && (t2 < s->endTime2))
						{
							// Gives slightly tighter bounds but runs slower:
							// minDistance = max(t, s->startTime);
							minDistance = s->startTime;
							maxDistance = s->endTime;
							break;
						}
					}

				}

				return *this;
			}

			/** Overloaded dereference operator so the iterator can masquerade as a pointer
			to a member */
			const TValue& operator*() const
			{
				alwaysAssertM(! isEnd, "Can't dereference the end element of an iterator");
				// return stack[stackIndex].node->valueArray[stack[stackIndex].valIndex].value;
				// return stack[stackIndex].node->getTriangleBox(iModelContainer,stack[stackIndex].valIndex);
				return(iNodeValueAccess.getValue(stack[stackIndex].valIndex+ stack[stackIndex].node->getStartPosition()));
			}

			/** Overloaded dereference operator so the iterator can masquerade as a pointer
			to a member */
			TValue const * operator->() const
			{
				alwaysAssertM(! isEnd, "Can't dereference the end element of an iterator");
				// return &(stack[stackIndex].node->valueArray[stack[stackIndex].valIndex].value);
				// return &stack[stackIndex].node->getTriangleBox(iModelContainer,stack[stackIndex].valIndex);
				return(&iNodeValueAccess.getValue(stack[stackIndex].valIndex+stack[stackIndex].node->getStartPosition()));

			}

			/** Overloaded cast operator so the iterator can masquerade as a pointer
			to a member */
			operator const TValue*() const
			{
				alwaysAssertM(! isEnd, "Can't dereference the end element of an iterator");
				//return &(stack[stackIndex].node->valueArray[stack[stackIndex].valIndex].value);
				//return &stack[stackIndex].node->getTriangleBox(iModelContainer,stack[stackIndex].valIndex);
				return(&iNodeValueAccess.getValue(stack[stackIndex].valIndex+stack[stackIndex].node->getStartPosition()));
			}

	};
}
#endif
