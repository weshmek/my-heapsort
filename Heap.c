#include "Heap.h"
#define HEAP_LEFT(i) (i << 1)
#define HEAP_RIGHT(i) ((i << 1) + 1)
#define HEAP_PARENT(i) (i >> 1)
typedef struct {heap_element *A; heap_length length;} Heap;

static Heap create_heap(heap_element *Arr, heap_length L)
{
	Heap ret;
	ret.A = Arr - 1;
	ret.length = L;
	return ret;
}


static void swap(Heap H, heap_index i, heap_index j)
{
	heap_element tmp = H.A[i];
	H.A[i] = H.A[j];
	H.A[j] = tmp;
}


static void max_heapify(Heap H, heap_index i)
{
	heap_index largest = i;
	do
	{
		heap_index Left, Right;
		i = largest;
		Left = HEAP_LEFT(i);
		Right = HEAP_RIGHT(i);
		if (Left <= H.length)
		{
			if (H.A[Left] > H.A[largest])
			{
				largest = Left;
			}
		}
		if (Right <= H.length)
		{
			if (H.A[Right] > H.A[largest])
			{
				largest = Right;
			}
		}
		swap(H, largest, i);
	} while(i != largest);
}		


static Heap build_max_heap(heap_element *A, heap_length L)
{
	heap_length l;
	Heap ret = create_heap(A, L);

	for (l = HEAP_PARENT(ret.length); l >= 1; l--)
	{
		max_heapify(ret, l);
	}
	return ret;
}


void Heapsort(heap_element *A, heap_length L)
{
	heap_length l;
	Heap H = build_max_heap(A, L);
	for (l = H.length; l >= 1; l--)
	{
		swap(H, 1, l);
		H.length--;
		max_heapify(H, 1);
	}
}