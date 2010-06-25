/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */
 
#ifndef CRC32_H
#define CRC32_H

// This computes a 32 bit CRC of the data in the buffer, and returns the
// CRC.  The polynomial used is 0xedb88320.
unsigned long crc32(const unsigned char *s, unsigned int len);

#endif // CRC32_H
