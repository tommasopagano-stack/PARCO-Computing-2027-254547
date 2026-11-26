#include "vector.h"

vector* vector_init(int *arr, int size) {
	vector *v = (vector*)malloc(sizeof(vector));
	
	if (arr == NULL) {
		arr = (int*)malloc(sizeof(int));
	}

        v->size = 0;
	v->max_size = 1;

	while (v->max_size < size) {
		v->max_size *= 2;
	}	

	v->head = (int*)realloc(arr, sizeof(int) * v->max_size);

        return v;
}

int vector_resize(vector *pv, int new_size) {

        if (new_size < 0) {
                perror("Invalid size provided");
                return 0;
        }
        
	int *old_ptr = pv->head;

        if (pv->head = (int*)realloc(pv, sizeof(int) * new_size) ) {
		pv->max_size = new_size;
                return 1;
        }
        else {
                pv->head = old_ptr;
                perror("Error in resizing vector");
                return 0;
        }
}

int vector_push_back (vector *pv, int el) {
	
	if (pv->size == pv->max_size) {

		if ( vector_resize(pv, pv->max_size * 2) == 0 )  {
			perror("Failed in adding element");
			return 0;
		}
	}

	else if (pv->max_size == 0) {
		if ( vector_resize(pv, 1) == 0 )  {
			perror("Failed in adding element");
			return 0;
		}
	}
	
	pv->head[pv->size++] = el;
	return 1;
}

