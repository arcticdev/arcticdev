/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#ifndef _AUTH_SHA1_H
#define _AUTH_SHA1_H

#include <stdlib.h>
#include "Common.h"
#include "../../../dep/vc/include/openssl/hmac.h"
#include "Auth/BigNumber.h"

class HMACHash
{
	public:
		HMACHash();
		~HMACHash();

		void UpdateFinalizeBigNumbers(BigNumber *bn0, ...);
		void UpdateBigNumber(BigNumber *bn0, ...);

		void UpdateData(const uint8 *dta, int len);
		void UpdateData(const std::string &str);

		void Initialize(uint32 len, uint8 *seed);
		void Finalize();

		uint8 *GetDigest(void) { return mDigest; };
		int GetLength(void) { return 20; };

		BigNumber GetBigNumber();

	private:
		HMAC_CTX mC;
		uint8 mDigest[20];
};

#endif
