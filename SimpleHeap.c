#include "SimpleHeap.h"


void HeapInit(Heap* ph, PriorityComp pc) {
	ph->numofData = 0;
	ph->comp = pc;
}
int HIsEmpty(Heap* ph) {
	if (ph->numofData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return 2 * idx;
}

int GetRChildIDX(int idx) {
	return 2 * idx + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx) {
	if (GetLChildIDX(idx) > ph->numofData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numofData)
		return GetLChildIDX(idx);
	else {
		if (ph->comp(ph->arr[GetLChildIDX(idx)], ph->arr[GetRChildIDX(idx)]) < 0) {
			return GetRChildIDX(idx);
		}
		else
			return GetLChildIDX(idx);
	}
}
void HInsert(Heap* ph, HData data) {
	int idx = ph->numofData + 1;

	while (idx != 1) {
		if (ph->comp(data, ph->arr[GetParentIDX(idx)]) > 0) {
			ph->arr[idx] = ph->arr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->arr[idx] = data;
	ph->numofData += 1;
}
int HDelete(Heap* ph) {
	HData retData = ph->arr[1];
	HData lastElem = ph->arr[ph->numofData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->arr[childIdx]) >= 0)
			break;
		ph->arr[parentIdx] = ph->arr[childIdx];
		parentIdx = childIdx;
	}

	ph->arr[parentIdx] = lastElem;
	ph->numofData -= 1;
	return retData;
}
