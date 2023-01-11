#ifndef __SIMPLE_HEAP__
#define __SIMPLE_HEAP__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int (*PriorityComp)(HData d1, HData d2);


typedef struct _heap {
	PriorityComp comp;
	int numofData;
	HData arr[HEAP_LEN];

}Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
int HDelete(Heap* ph);

#endif // !__SIMPLE_HEAP__
