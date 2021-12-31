#include <stdio.h>
#include <stdlib.h>

// Heaps are usually implemented with an array:
// Each element in the array represents a node of the heap
// The parent/child relationship is defined implicitly by the elements' indices in the array
/*
              30
              / \
             /   \
            /     \
          15       25
         /  \     /  \
        /    \   /    \
       5     10 20     2
       
    ┌──────────────────────────────┐
    │  30  15  25   5  10  20   2  │
    └──────────────────────────────┘
idx:    0   1   2   3   4   5   6
*/

struct MaxHeap
{
    int *elements;
    int count;
    int capacity;
};

typedef struct MaxHeap *heap;

heap CreateHeap(int capacity)
{
    heap h = (heap)malloc(sizeof(struct MaxHeap));
    h->count = 0;
    h->capacity = capacity;
    h->elements = (int *)malloc(capacity * sizeof(int));
    return h;
}

void HeapifyBottomTop(heap h, int index)
{
    int temp;
    int parent_node = (index - 1) / 2;

    if (h->elements[parent_node] < h->elements[index])
    {
        temp = h->elements[parent_node];
        h->elements[parent_node] = h->elements[index];
        h->elements[index] = temp;
        HeapifyBottomTop(h, parent_node);
    }
}

void InsertElement(heap h, int element)
{
    if (h->count < h->capacity)
    {
        h->elements[h->count] = element;
        HeapifyBottomTop(h, h->count);
        h->count++;
    }
}

void PrintHeap(heap h)
{
    printf("[ ");
    for (int i = 0; i < h->count; i++)
    {
        printf("%d ", h->elements[i]);
    }
    printf("]\n");
}

int main()
{
    heap h;
    h = CreateHeap(10);

    InsertElement(h, 10);
    InsertElement(h, 20);
    InsertElement(h, 30);
    InsertElement(h, 5);
    InsertElement(h, 15);
    InsertElement(h, 25);
    InsertElement(h, 2);

    PrintHeap(h);
    return 0;
}