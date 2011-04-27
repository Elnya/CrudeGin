//
//  CGNumber.h
//  CrudeGin
//
//  Created by Cyrus Hackford on 2011.
//  Copyright 2011 SI devIk. All rights reserved.
//

#ifndef _CGNUMBER_H_
#define _CGNUMBER_H_

#include "CGError.h"
#include "CGTypes.h"

//@ CGNumber
union _CGNumbers {
	CGLong l;
	CGULong ul;
	CGDouble d;
	CGInteger i[2];
	CGUInteger ui[2];
	CGFloat f[2];
	CGShort s[4];
	CGUShort us[4];
	CGByte b[8];
	CGUByte ub[8];
};

typedef struct _CGNumber {
	union _CGNumbers number;
	CGUByte numberType;
} CGNumber;

//@ Constants
#define CGNUMBER_TYPE_UNDEFINED ((CGUByte)0x00)
#define CGNUMBER_TYPE_BYTE ((CGUByte)0x01)
#define CGNUMBER_TYPE_UBYTE ((CGUByte)0x02)
#define CGNUMBER_TYPE_SHORT ((CGUByte)0x03)
#define CGNUMBER_TYPE_USHORT ((CGUByte)0x04)
#define CGNUMBER_TYPE_INTEGER ((CGUByte)0x05)
#define CGNUMBER_TYPE_UINTEGER ((CGUByte)0x06)
#define CGNUMBER_TYPE_LONG ((CGUByte)0x07)
#define CGNUMBER_TYPE_ULONG ((CGUByte)0x08)
#define CGNUMBER_TYPE_FLOAT ((CGUByte)0x09)
#define CGNUMBER_TYPE_DOUBLE ((CGUByte)0x0A)


//@ Methods
static BOOL CGNumberMake(CGNumber **);
static BOOL CGNumberWithByte(CGNumber **, CGByte);
static BOOL CGNumberWithUByte(CGNumber **, CGUByte);
static BOOL CGNumberWithShort(CGNumber **, CGShort);
static BOOL CGNumberWithUShort(CGNumber **, CGUShort);
static BOOL CGNumberWithInteger(CGNumber **, CGInteger);
static BOOL CGNumberWithUInteger(CGNumber **, CGUInteger);
static BOOL CGNumberWithLong(CGNumber **, CGLong);
static BOOL CGNumberWithULong(CGNumber **, CGULong);
static BOOL CGNumberWithFloat(CGNumber **, CGFloat);
static BOOL CGNumberWithDouble(CGNumber **, CGDouble);
static void CGNumberRelease(CGNumber **);
static CGUByte CGNumberType(CGNumber *);
static CGByte CGNumberByteValue(CGNumber *);
static CGUByte CGNumberUByteValue(CGNumber *);
static CGShort CGNumberShortValue(CGNumber *);
static CGUShort CGNumberUShortValue(CGNumber *);
static CGInteger CGNumberIntegerValue(CGNumber *);
static CGUInteger CGNumberUIntegerValue(CGNumber *);
static CGLong CGNumberLongValue(CGNumber *);
static CGULong CGNumberULongValue(CGNumber *);
static CGFloat CGNumberFloatValue(CGNumber *);
static CGDouble CGNumberDoubleValue(CGNumber *);

#endif