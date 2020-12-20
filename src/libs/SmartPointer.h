/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#pragma once

template <class T> class SharedPointer;
template <class T>
class PointerReference
{
	friend class SharedPointer<T>;
private:
	PointerReference(T* pT) : Count(0), my_pT(pT) { ASSERT(pT != 0); }
	~PointerReference() { ASSERT(Count == 0); delete my_pT; }

	unsigned GetRef() { return ++Count; }
	unsigned FreeRef() {  ASSERT(Count!=0); return --Count; }

	T* const my_pT;
	unsigned Count;
};

template <class T>
class SharedPointer
{
public:
	SharedPointer()
	{
		m_Reference = 0;
	}

	SharedPointer(T* pT)
	{
		if(!pT) { m_Reference = 0; return; }

		m_Reference = new PointerReference<T>(pT);
		m_Reference->GetRef();
	}

	SharedPointer(const SharedPointer<T>& rVar)
	{
		m_Reference = rVar.m_Reference;
		if(!Null())
			m_Reference->GetRef();
	}

	~SharedPointer()
	{
		UnBind();
	}

	T& operator*()
	{
		if(Null())
			return NULL;
		//  throw NulRefException();
		return *m_Reference->my_pT;
	}

	T* operator->()
	{
		if (Null())
			return NULL;
		//  throw NulRefException();
		return m_Reference->my_pT;
	}

	const T* operator->() const
	{
		if(Null())
			return NULL;
		//throw NulRefException();
		return m_Reference->my_pT;
	}

	SharedPointer<T> & operator = (const SharedPointer<T> & rVar)
	{
		if(!rVar.Null())
			rVar.m_Reference->GetRef();
		UnBind();
		m_Reference = rVar.m_Reference;
		return *this;
	}

	bool operator == (const SharedPointer<T> & lhs)
	{
		return this->m_Reference == lhs.m_Reference;
	}

	bool operator != (const SharedPointer<T> & lhs)
	{
		return !(*this == lhs);
	}

	bool Null() const {return m_Reference == 0; }
	void SetNull() { UnBind(); }

private:
	void UnBind()
	{
		if (!Null() && m_Reference->FreeRef() == 0)
			delete m_Reference;
		m_Reference = 0;
	}
	PointerReference<T>* m_Reference;
};
