#include "Heap.h"
#include <stdio.h>


int main(void)
{
	heap_index i;
	heap_element A[] = {2, 7, 1, 8, 4, 9};
	Heapsort(A, sizeof(A) / sizeof(A[0]));
	for (i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		printf("%f\t", A[i]);
	}
	printf("\n");
}