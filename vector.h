#ifndef __VECTOR_H__
#define __VECTOR_H__

#include<stdlib.h>
#include<stdio.h>

typedef struct vector {
	int *head;
	int size, max_size;
} vector;

vector* vector_init(int *arr, int size); 

int vector_resize(vector *pv, int new_size); 

int vector_push_back (vector *pv, int el);

#endif

