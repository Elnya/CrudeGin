//
//  CGNumber.c
//  CrudeGin
//
//  Created by Cyrus Hackford on 2011.
//  Copyright 2011 SI devIk. All rights reserved.
//

#include <stdlib.h>
#include <strings.h>
#include "CGNumber.h"


static BOOL CGNumberMake(CGNumber **emptyNumber) {
	CGError_globalError=CGERROR_NOTHING;
	
	*emptyNumber=(CGNumber *)malloc(sizeof(CGNumber));
	if(*emptyNumber==NULL) {
		CGError_globalError=CGERROR_ALLOC_FAIL;
		
		return NO;
	}
	
	memset(*emptyNumber, 0, sizeof(CGNumber));
	
	return YES;
}

static BOOL CGNumberWithByte(CGNumber **emptyNumber, CGByte num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.b[7]=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_BYTE;
	
	return YES;
}

static BOOL CGNumberWithUByte(CGNumber **emptyNumber, CGUByte num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.ub[7]=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_UBYTE;
	
	return YES;
}

static BOOL CGNumberWithShort(CGNumber **emptyNumber, CGShort num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.s[3]=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_SHORT;
	
	return YES;
}

static BOOL CGNumberWithUShort(CGNumber **emptyNumber, CGUShort num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.us[3]=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_USHORT;
	
	return YES;
}

static BOOL CGNumberWithInteger(CGNumber **emptyNumber, CGInteger num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.i[1]=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_INTEGER;
	
	return YES;
}

static BOOL CGNumberWithUInteger(CGNumber **emptyNumber, CGUInteger num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.ui[1]=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_UINTEGER;
	
	return YES;
}

static BOOL CGNumberWithLong(CGNumber **emptyNumber, CGLong num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.l=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_LONG;
	
	return YES;
}

static BOOL CGNumberWithULong(CGNumber **emptyNumber, CGULong num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.ul=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_ULONG;
	
	return YES;
}

static BOOL CGNumberWithFloat(CGNumber **emptyNumber, CGFloat num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.f[1]=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_FLOAT;
	
	return YES;
}

static BOOL CGNumberWithDouble(CGNumber **emptyNumber, CGDouble num) {
	if(CGNumberMake(emptyNumber)==NO)
		return NO;
	
	(*emptyNumber)->number.d=num;
	(*emptyNumber)->numberType=CGNUMBER_TYPE_DOUBLE;
	
	return YES;
}

static void CGNumberRelease(CGNumber **number) {
	free(*number);
	*number=NULL;
}

static CGUByte CGNumberType(CGNumber *number) {
	return number->numberType;
}

static CGByte CGNumberByteValue(CGNumber *number) {
	return number->number.b[7];
}

static CGUByte CGNumberUByteValue(CGNumber *number) {
	return number->number.b[7];
}

static CGShort CGNumberShortValue(CGNumber *number) {
	return number->number.s[3];
}

static CGUShort CGNumberUShortValue(CGNumber *number) {
	return number->number.us[3];
}

static CGInteger CGNumberIntegerValue(CGNumber *number) {
	return number->number.i[1];
}

static CGUInteger CGNumberUIntegerValue(CGNumber *number) {
	return number->number.ui[1];
}

static CGLong CGNumberLongValue(CGNumber *number) {
	return number->number.l;
}

static CGULong CGNumberULongValue(CGNumber *number) {
	return number->number.ul;
}

static CGFloat CGNumberFloatValue(CGNumber *number) {
	return number->number.f[1];
}

static CGDouble CGNumberDoubleValue(CGNumber *number) {
	return number->number.d;
}