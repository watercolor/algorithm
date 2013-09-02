#include <stdio.h>
#include <stdlib.h>

#define HEAPLEN 1024
#define ElemType    int
typedef struct  {
    ElemType *array;
    int lastidx;
    int size;
} HeapS;

inline int HeapIsFull(HeapS *heap)
{
    return heap->lastidx >= (heap->size - 1) ;
}

inline int HeapIsEmpty(HeapS *heap)
{
    return heap->lastidx == 0;
}

int HeapInsert(HeapS *heap, ElemType inval)
{
    int idx;
    int *array = heap->array;
    if(HeapIsFull(heap)) {
        printf("Error: heap is full\n");
        return 0;
    }
    /* first add lastidx, assume inval position in lastidx
     * then if father val is bigger than inval, move father elem to child
     * until find the right position.
     */
    for (idx = ++heap->lastidx; (idx > 1) && array[idx/2] > inval; idx /= 2) {
        array[idx] = array[idx/2];
    }
    array[idx] = inval;
    return idx;
}

ElemType HeapPopMost(HeapS *heap)
{
    ElemType topelem, lastelem;
    int idx, child;
    ElemType *array = heap->array;

    if(HeapIsEmpty(heap))
        return 0;
    /* get top elem */
    topelem = array[1];
    /* get last elem, decrease lastidx, for we pop top elem */
    lastelem = heap->array[heap->lastidx--];
    /* idx = 1 : walk from top
     * idx*2 <= lastidx : make sure we will not walk through the array lastidx
     * idx = child : we walk follow the smaller child path
     */
    for (idx = 1; idx * 2 <= heap->lastidx; idx = child) {
        /* find a smaller child */
        child = idx * 2;
        /* if child != lastidx, child + 1 is ok */
        if(child != heap->lastidx && array[child] > array[child + 1] )
            child++;
        /* if lastelem <= child, we can just put lastelem in idx
         * and finish the walk.
         * NOT EACH ELEM IN NEXT LEVEL IS BIGGER THAN THIS LEVEL
         */
        if(lastelem > array[child])
            array[idx] = array[child];
        else
            break;
    }
    array[idx] = lastelem;
    return topelem;

}
HeapS * HeapInit(int capacity)
{
    HeapS *heap = malloc(sizeof(HeapS));
    if(heap == NULL)
        return NULL;
    heap->array = malloc(sizeof(ElemType) * capacity);
    if(heap->array == NULL) {
        free(heap);
        return NULL;
    }
    heap->size = capacity;
    heap->lastidx = 0;
    return heap;
}

void HeapFree(HeapS *heap)
{
    if(heap->array)
        free(heap->array);
    free(heap);
    return;
}

void HeapPrint(HeapS *heap)
{
    int i;
    for (i = 1; i <= heap->lastidx; i++) {
        if((i & 0xf) == 0)
            printf("\n");
        printf("%d ", heap->array[i]);
    }
}

int testHeap(int argc, const char *argv[])
{
    HeapS *heap = HeapInit(HEAPLEN);
    int a = 0;
    int top = 0;
    while(scanf("%d", &a) == 1) {
        if(a == 0) {
            top = HeapPopMost(heap);
            printf("pop %d\n", top);
            continue;
        }
        HeapInsert(heap, a);
    }
    HeapPrint(heap);
    return 0;
}
