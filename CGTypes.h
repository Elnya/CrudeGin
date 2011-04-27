//
//  CGTypes.h
//  CrudeGin
//
//  Created by Cyrus Hackford on 2011.
//  Copyright 2011 SI devIk. All rights reserved.
//

#ifndef _CGTYPES_H_
#define _CGTYPES_H_

// To use (u)int*_t
#include <stdint.h>
#include "CGBase.h"

//@ BOOL

#ifndef OBJC_BOOL_DEFINED
#define OBJC_BOOL_DEFINED

typedef signed char BOOL;
#define YES ((BOOL)1)
#define NO ((BOOL)0)

#endif


//@ General character types
//typedef char CGChar;
//typedef unsigned char CGUChar;

//@ General integer types
typedef int8_t CGByte;
typedef int16_t CGShort;
typedef int32_t CGInteger;
typedef int64_t CGLong;

typedef uint8_t CGUByte;
typedef uint16_t CGUShort;
typedef uint32_t CGUInteger;
typedef uint64_t CGULong;

typedef float CGFloat; // fixed to 32-bit, by IEEE 754-2008
typedef double CGDouble; // fixed to 64-bit, by IEEE 754-2008

#endif