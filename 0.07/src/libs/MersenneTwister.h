/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _RANDOMGEN_H
#define _RANDOMGEN_H

#include "Common.h"
#include "Singleton.h"

SERVER_DECL void InitRandomNumberGenerators();
SERVER_DECL void ReseedRandomNumberGenerators();
SERVER_DECL void CleanupRandomNumberGenerators();
SERVER_DECL double RandomDouble();
SERVER_DECL double RandomDouble(double n);
SERVER_DECL float RandomFloat();
SERVER_DECL float RandomFloat(float n);
SERVER_DECL uint32 RandomUInt();
SERVER_DECL uint32 RandomUInt(uint32 n);

//////////////////////////////////////////////////////////////
// Define random number generator classes
//////////////////////////////////////////////////////////////

class CRandomMersenne {   // Encapsulate random number generator
#if 0
// Define constants for type MT11213A:
#define MERS_N   351
#define MERS_M   175
#define MERS_R   19
#define MERS_U   11
#define MERS_S   7
#define MERS_T   15
#define MERS_L   17
#define MERS_A   0xE4BD75F5
#define MERS_B   0x655E5280
#define MERS_C   0xFFD58000
#else    
// or constants for type MT19937:
#define MERS_N   624
#define MERS_M   397
#define MERS_R   31
#define MERS_U   11
#define MERS_S   7
#define MERS_T   15
#define MERS_L   18
#define MERS_A   0x9908B0DF
#define MERS_B   0x9D2C5680
#define MERS_C   0xEFC60000
#endif
public:
	CRandomMersenne(uint32 seed) {                              // Constructor
		 RandomInit(seed); LastInterval = 0;}                   // 
	void RandomInit(uint32 seed);                               // Re-seed
	void RandomInitByArray(uint32 seeds[], int length);         // Seed by more than 32 bits
	int IRandom (int min, int max);                             // Output random integer
	int IRandomX(int min, int max);                             // Output random integer, exact
	double Random();                                            // Output random float
	uint32 BRandom();                                           // Output random bits
private:                                                        //
	void Init0(uint32 seed);                                    // Basic initialization procedure
	uint32 mt[MERS_N];                                          // State vector
	int mti;                                                    // Index into mt
	uint32 LastInterval;                                        // Last interval length for IRandomX
	uint32 RLimit;                                              // Rejection limit used by IRandomX
	enum TArch {LITTLE_ENDIAN1, BIG_ENDIAN1, NONIEEE};          // Definition of architecture
	TArch Architecture;                                         // Conversion to float depends on architecture
};    

#endif
