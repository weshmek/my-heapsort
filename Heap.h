#ifndef __HEAP_H__
#define __HEAP_H__

#ifndef heap_type
#define heap_type char
#endif
typedef heap_type heap_element;
typedef unsigned long heap_index;
typedef heap_index heap_length;

void Heapsort(heap_element *, heap_length);


#endif
