/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#if !defined(FIELD_H)
#define FIELD_H

class Field
{
public:

	ARCTIC_INLINE void SetValue(char* value) { mValue = value; }

	ARCTIC_INLINE const char *GetString() { return mValue; }
	ARCTIC_INLINE float GetFloat() { return mValue ? static_cast<float>(atof(mValue)) : 0; }
	ARCTIC_INLINE bool GetBool() { return mValue ? atoi(mValue) > 0 : false; }
	ARCTIC_INLINE uint8 GetUInt8() { return mValue ? static_cast<uint8>(atol(mValue)) : 0; }
	ARCTIC_INLINE int8 GetInt8() { return mValue ? static_cast<int8>(atol(mValue)) : 0; }
	ARCTIC_INLINE uint16 GetUInt16() { return mValue ? static_cast<uint16>(atol(mValue)) : 0; }
	ARCTIC_INLINE int16 GetInt16() { return mValue ? static_cast<int16>(atol(mValue)) : 0; }
	ARCTIC_INLINE uint32 GetUInt32() { return mValue ? static_cast<uint32>(atol(mValue)) : 0; }
	ARCTIC_INLINE int32 GetInt32() { return mValue ? static_cast<int32>(atol(mValue)) : 0; }
	uint64 GetUInt64() 
	{
		if(mValue)
		{
			uint64 value;
#if !defined(WIN32) && defined(X64)
			sscanf(mValue,I64FMTD,(long long unsigned int*)&value);
#else
			sscanf(mValue,I64FMTD,&value);
#endif
			return value;
		}
		else
			return 0;
	}

private:
		char *mValue;
};

#endif
