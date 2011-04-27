//
//  CGNumberArray.c
//  CrudeGin
//
//  Created by Cyrus Hackford on 2011.
//  Copyright 2011 SI devIk. All rights reserved.
//

#include <stdarg.h>
#include <stdlib.h>
#include <strings.h>
#include "CGNumberArray.h"

static BOOL CGNumberArrayMake(CGNumberArray **emptyArray) {
	CGError_globalError=CGERROR_NOTHING;
	
	*emptyArray=(CGNumberArray *)malloc(sizeof(CGNumberArray));
	if(*emptyArray==NULL) {
		CGError_globalError=CGERROR_ALLOC_FAIL;
		
		return NO;
	}
	
	memset(*emptyArray, 0, sizeof(CGNumberArray));
	
	return YES;
}

static BOOL CGNumberArrayWithNumber(CGNumberArray **emptyArray, CGNumber *number) {
	if(CGNumberArrayMake(emptyArray)==NO)
		return NO;
	
	if(CGNumberArrayAddNumber(*emptyArray, number)==NO)
		return NO;
	
	return YES;
}

static BOOL CGNumberArrayWithNumbers(CGNumberArray **emptyArray, CGULong howMany, ...) {
	va_list argv;
	
	if(CGNumberArrayMake(emptyArray)==NO)
		return NO;
	
	BOOL errorEmitted=NO;
	va_start(argv, howMany);
	for(CGULong loopy=0; loopy<howMany; ++loopy) {
		if(CGNumberArrayAddNumber(*emptyArray, va_arg(argv, CGNumber *))==NO) {
			errorEmitted=YES;
			
			break;
		}
	}
	va_end(argv);
	
	if(errorEmitted==YES)
		return NO;
	
	return YES;
}

static BOOL CGNumberArrayAddNumber(CGNumberArray *array, CGNumber *number) {
	CGError_globalError=CGERROR_NOTHING;
	
	struct _CGNumberArrayNode *newNode=(CGNumberArrayNode *)malloc(sizeof(CGNumberArrayNode));
	if(newNode==NULL) {
		CGError_globalError=CGERROR_ALLOC_FAIL;
		
		return NO;
	}
	
	memset(newNode, 0, sizeof(CGNumberArrayNode));
	newNode->number=number;
	
	if(array->tail==NULL)
		array->head=array->tail=newNode;
	else {
		array->tail->next=newNode;
		newNode->prev=array->tail;
		array->tail=newNode;
	}
	++(array->count);
	
	return YES;
}