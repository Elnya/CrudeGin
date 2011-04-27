//
//  CGError.h
//  CrudeGin
//
//  Created by Cyrus Hackford on 2011.
//  Copyright 2011 SI devIk. All rights reserved.
//

#ifndef _CGERROR_H_
#define _CGERROR_H_

#include "CGTypes.h"

//@ Global error indicator. You should NOT access this variable directly.
CGUByte CGError_globalError;

//@ Errors
#define CGERROR_NOTHING ((CGUByte)0x00)
#define CGERROR_ALLOC_FAIL ((CGUByte)0x01)
#define CGERROR_REALLOC_FAIL ((CGUByte)0x02)
#define CGERROR_OUT_OF_BOUND ((CGUByte)0x03)

#endif