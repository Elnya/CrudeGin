//
//  CGNumberArray.h
//  CrudeGin
//
//  Created by Cyrus Hackford on 2011.
//  Copyright 2011 SI devIk. All rights reserved.
//

#ifndef _CGNUMBERARRAY_H_
#define _CGNUMBERARRAY_H_

#include "CGNumber.h"

//@ CGNumberArrayNode
typedef struct _CGNumberArrayNode CGNumberArrayNode;
struct _CGNumberArrayNode {
	CGNumberArrayNode *prev;
	CGNumberArrayNode *next;
	CGNumber *number;
};

//@ CGNumberArray
typedef struct _CGNumberArray {
	CGNumberArrayNode *head;
	CGNumberArrayNode *tail;
	CGULong count;
} CGNumberArray;


//@ Methods
static BOOL CGNumberArrayMake(CGNumberArray **);
static BOOL CGNumberArrayWithNumber(CGNumberArray **, CGNumber *);
static BOOL CGNumberArrayWithNumbers(CGNumberArray **, CGULong, ...);
static BOOL CGNumberArrayAddNumber(CGNumberArray *, CGNumber *);

#endif