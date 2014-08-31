#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	heap_element *A;
	heap_index l;
	A = malloc((argc - 1) * sizeof(heap_element));
	for (l = 0; l < argc - 1; l++)
	{
		A[l] = (heap_element) atoi(argv[l + 1]);
	}
	Heapsort(A, argc - 1);
	for (l = 0; l < argc - 1; l++)
	{
		printf("%f\t", A[l]);
	}
	printf("\n");
	free(A);
}