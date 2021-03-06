/*
 * Copyright (c) 2000-2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _OS_OSBYTEORDER_H
#define _OS_OSBYTEORDER_H

#include <stdint.h>

/* Macros for swapping constant values in the preprocessing stage. */
#define OSSwapConstInt16(x) \
    ((uint16_t)((((uint16_t)(x) & 0xff00) >> 8) | \
                (((uint16_t)(x) & 0x00ff) << 8)))

#define OSSwapConstInt32(x) \
    ((uint32_t)((((uint32_t)(x) & 0xff000000) >> 24) | \
                (((uint32_t)(x) & 0x00ff0000) >>  8) | \
                (((uint32_t)(x) & 0x0000ff00) <<  8) | \
                (((uint32_t)(x) & 0x000000ff) << 24)))

#define OSSwapConstInt64(x) \
    ((uint64_t)((((uint64_t)(x) & 0xff00000000000000ULL) >> 56) | \
                (((uint64_t)(x) & 0x00ff000000000000ULL) >> 40) | \
                (((uint64_t)(x) & 0x0000ff0000000000ULL) >> 24) | \
                (((uint64_t)(x) & 0x000000ff00000000ULL) >>  8) | \
                (((uint64_t)(x) & 0x00000000ff000000ULL) <<  8) | \
                (((uint64_t)(x) & 0x0000000000ff0000ULL) << 24) | \
                (((uint64_t)(x) & 0x000000000000ff00ULL) << 40) | \
                (((uint64_t)(x) & 0x00000000000000ffULL) << 56)))

#if defined(__GNUC_UNUSED__)

#if (defined(__ppc__) || defined(__ppc64__))
#include <libkern/ppc/OSByteOrder.h>
#elif (defined(__i386__) || defined(__x86_64__))
#include <libkern/i386/OSByteOrder.h>
#else
#include <libkern/machine/OSByteOrder.h>
#endif

#define OSSwapInt16(x) \
    (__builtin_constant_p(x) ? OSSwapConstInt16(x) : _OSSwapInt16(x))

#define OSSwapInt32(x) \
    (__builtin_constant_p(x) ? OSSwapConstInt32(x) : _OSSwapInt32(x))

#define OSSwapInt64(x) \
    (__builtin_constant_p(x) ? OSSwapConstInt64(x) : _OSSwapInt64(x))

#else /* ! __GNUC_UNUSED__ */

#include <libkern/machine/OSByteOrder.h>

#define OSSwapInt16(x) OSSwapConstInt16(x)

#define OSSwapInt32(x) OSSwapConstInt32(x)

#define OSSwapInt64(x) OSSwapConstInt64(x)

#endif /* __GNUC_UNUSED__ */

enum {
    OSUnknownByteOrder,
    OSLittleEndian,
    OSBigEndian
};

OS_INLINE
int32_t
OSHostByteOrder(void) {
#if defined(__LITTLE_ENDIAN__)
    return OSLittleEndian;
#elif defined(__BIG_ENDIAN__)
    return OSBigEndian;
#else
    return OSUnknownByteOrder;
#endif
}

#define OSReadBigInt(x, y)		OSReadBigInt32(x, y)
#define OSWriteBigInt(x, y, z)		OSWriteBigInt32(x, y, z)
#define OSSwapBigToHostInt(x)		OSSwapBigToHostInt32(x)
#define OSSwapHostToBigInt(x)		OSSwapHostToBigInt32(x)
#define OSReadLittleInt(x, y)		OSReadLittleInt32(x, y)
#define OSWriteLittleInt(x, y, z)	OSWriteLittleInt32(x, y, z)
#define OSSwapHostToLittleInt(x)	OSSwapHostToLittleInt32(x)
#define OSSwapLittleToHostInt(x)	OSSwapLittleToHostInt32(x)

/* Functions for loading native endian values. */

OS_INLINE
uint16_t
_OSReadInt16(
    const volatile void               * base,
    uintptr_t                     byteOffset
)
{
    return *(volatile uint16_t *)((uintptr_t)base + byteOffset);
}

OS_INLINE
uint32_t
_OSReadInt32(
    const volatile void               * base,
    uintptr_t                     byteOffset
)
{
    return *(volatile uint32_t *)((uintptr_t)base + byteOffset);
}

OS_INLINE
uint64_t
_OSReadInt64(
    const volatile void               * base,
    uintptr_t                     byteOffset
)
{
    return *(volatile uint64_t *)((uintptr_t)base + byteOffset);
}

/* Functions for storing native endian values. */

OS_INLINE
void
_OSWriteInt16(
    volatile void               * base,
    uintptr_t                     byteOffset,
    uint16_t                      data
)
{
    *(volatile uint16_t *)((uintptr_t)base + byteOffset) = data;
}

OS_INLINE
void
_OSWriteInt32(
    volatile void               * base,
    uintptr_t                     byteOffset,
    uint32_t                      data
)
{
    *(volatile uint32_t *)((uintptr_t)base + byteOffset) = data;
}

OS_INLINE
void
_OSWriteInt64(
    volatile void               * base,
    uintptr_t                     byteOffset,
    uint64_t                      data
)
{
    *(volatile uint64_t *)((uintptr_t)base + byteOffset) = data;
}

#if		defined(__BIG_ENDIAN__)

/* Functions for loading big endian to host endianess. */

#define OSReadBigInt16(base, byteOffset) _OSReadInt16(base, byteOffset)
#define OSReadBigInt32(base, byteOffset) _OSReadInt32(base, byteOffset)
#define OSReadBigInt64(base, byteOffset) _OSReadInt64(base, byteOffset)

/* Functions for storing host endianess to big endian. */

#define OSWriteBigInt16(base, byteOffset, data) _OSWriteInt16(base, byteOffset, data)
#define OSWriteBigInt32(base, byteOffset, data) _OSWriteInt32(base, byteOffset, data)
#define OSWriteBigInt64(base, byteOffset, data) _OSWriteInt64(base, byteOffset, data)

/* Functions for loading little endian to host endianess. */

#define OSReadLittleInt16(base, byteOffset) OSReadSwapInt16(base, byteOffset)
#define OSReadLittleInt32(base, byteOffset) OSReadSwapInt32(base, byteOffset)
#define OSReadLittleInt64(base, byteOffset) OSReadSwapInt64(base, byteOffset)

/* Functions for storing host endianess to little endian. */

#define OSWriteLittleInt16(base, byteOffset, data) OSWriteSwapInt16(base, byteOffset, data)
#define OSWriteLittleInt32(base, byteOffset, data) OSWriteSwapInt32(base, byteOffset, data)
#define OSWriteLittleInt64(base, byteOffset, data) OSWriteSwapInt64(base, byteOffset, data)

/* Host endianess to big endian byte swapping macros for constants. */

#define OSSwapHostToBigConstInt16(x) (x)
#define OSSwapHostToBigConstInt32(x) (x)
#define OSSwapHostToBigConstInt64(x) (x)

/* Generic host endianess to big endian byte swapping functions. */

#define OSSwapHostToBigInt16(x) ((uint16_t)(x))
#define OSSwapHostToBigInt32(x) ((uint32_t)(x))
#define OSSwapHostToBigInt64(x) ((uint64_t)(x))

/* Host endianess to little endian byte swapping macros for constants. */

#define OSSwapHostToLittleConstInt16(x) OSSwapConstInt16(x)
#define OSSwapHostToLittleConstInt32(x) OSSwapConstInt32(x) 
#define OSSwapHostToLittleConstInt64(x) OSSwapConstInt64(x) 

/* Generic host endianess to little endian byte swapping functions. */

#define OSSwapHostToLittleInt16(x) OSSwapInt16(x)
#define OSSwapHostToLittleInt32(x) OSSwapInt32(x)
#define OSSwapHostToLittleInt64(x) OSSwapInt64(x)

/* Big endian to host endianess byte swapping macros for constants. */
    
#define OSSwapBigToHostConstInt16(x) (x)
#define OSSwapBigToHostConstInt32(x) (x)
#define OSSwapBigToHostConstInt64(x) (x)

/* Generic big endian to host endianess byte swapping functions. */

#define OSSwapBigToHostInt16(x) ((uint16_t)(x))
#define OSSwapBigToHostInt32(x) ((uint32_t)(x))
#define OSSwapBigToHostInt64(x) ((uint64_t)(x))

/* Little endian to host endianess byte swapping macros for constants. */
   
#define OSSwapLittleToHostConstInt16(x) OSSwapConstInt16(x)
#define OSSwapLittleToHostConstInt32(x) OSSwapConstInt32(x)
#define OSSwapLittleToHostConstInt64(x) OSSwapConstInt64(x)

/* Generic little endian to host endianess byte swapping functions. */

#define OSSwapLittleToHostInt16(x) OSSwapInt16(x)
#define OSSwapLittleToHostInt32(x) OSSwapInt32(x)
#define OSSwapLittleToHostInt64(x) OSSwapInt64(x)

#elif		defined(__LITTLE_ENDIAN__)

/* Functions for loading big endian to host endianess. */

#define OSReadBigInt16(base, byteOffset) OSReadSwapInt16(base, byteOffset)
#define OSReadBigInt32(base, byteOffset) OSReadSwapInt32(base, byteOffset)
#define OSReadBigInt64(base, byteOffset) OSReadSwapInt64(base, byteOffset)

/* Functions for storing host endianess to big endian. */

#define OSWriteBigInt16(base, byteOffset, data) OSWriteSwapInt16(base, byteOffset, data)
#define OSWriteBigInt32(base, byteOffset, data) OSWriteSwapInt32(base, byteOffset, data)
#define OSWriteBigInt64(base, byteOffset, data) OSWriteSwapInt64(base, byteOffset, data)

/* Functions for loading little endian to host endianess. */

#define OSReadLittleInt16(base, byteOffset) _OSReadInt16(base, byteOffset)
#define OSReadLittleInt32(base, byteOffset) _OSReadInt32(base, byteOffset)
#define OSReadLittleInt64(base, byteOffset) _OSReadInt64(base, byteOffset)

/* Functions for storing host endianess to little endian. */

#define OSWriteLittleInt16(base, byteOffset, data) _OSWriteInt16(base, byteOffset, data)
#define OSWriteLittleInt32(base, byteOffset, data) _OSWriteInt32(base, byteOffset, data)
#define OSWriteLittleInt64(base, byteOffset, data) _OSWriteInt64(base, byteOffset, data)

/* Host endianess to big endian byte swapping macros for constants. */

#define OSSwapHostToBigConstInt16(x) OSSwapConstInt16(x)
#define OSSwapHostToBigConstInt32(x) OSSwapConstInt32(x)
#define OSSwapHostToBigConstInt64(x) OSSwapConstInt64(x)

/* Generic host endianess to big endian byte swapping functions. */

#define OSSwapHostToBigInt16(x) OSSwapInt16(x)
#define OSSwapHostToBigInt32(x) OSSwapInt32(x)
#define OSSwapHostToBigInt64(x) OSSwapInt64(x)

/* Host endianess to little endian byte swapping macros for constants. */

#define OSSwapHostToLittleConstInt16(x) (x)
#define OSSwapHostToLittleConstInt32(x) (x)
#define OSSwapHostToLittleConstInt64(x) (x) 

/* Generic host endianess to little endian byte swapping functions. */

#define OSSwapHostToLittleInt16(x) ((uint16_t)(x))
#define OSSwapHostToLittleInt32(x) ((uint32_t)(x))
#define OSSwapHostToLittleInt64(x) ((uint64_t)(x))

/* Big endian to host endianess byte swapping macros for constants. */

#define OSSwapBigToHostConstInt16(x) OSSwapConstInt16(x)
#define OSSwapBigToHostConstInt32(x) OSSwapConstInt32(x)
#define OSSwapBigToHostConstInt64(x) OSSwapConstInt64(x)

/* Generic big endian to host endianess byte swapping functions. */

#define OSSwapBigToHostInt16(x) OSSwapInt16(x)
#define OSSwapBigToHostInt32(x) OSSwapInt32(x)
#define OSSwapBigToHostInt64(x) OSSwapInt64(x)

/* Little endian to host endianess byte swapping macros for constants. */

#define OSSwapLittleToHostConstInt16(x) (x)
#define OSSwapLittleToHostConstInt32(x) (x)
#define OSSwapLittleToHostConstInt64(x) (x)

/* Generic little endian to host endianess byte swapping functions. */

#define OSSwapLittleToHostInt16(x) ((uint16_t)(x))
#define OSSwapLittleToHostInt32(x) ((uint32_t)(x))
#define OSSwapLittleToHostInt64(x) ((uint64_t)(x))

#else
#error Unknown endianess.
#endif

#endif /* ! _OS_OSBYTEORDER_H */


