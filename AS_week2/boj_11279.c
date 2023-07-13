// 최대 힙
// 완전 이진 트리

#include <stdio.h>
#include <stdlib.h>

typedef struct maxHeap
{
    int *node;
    int size; // 총 노드의 개수
} maxHeap;

int max_heap_pop(maxHeap *h);
void max_heap_push(maxHeap *h, int data);

int main()
{
    int num, n, i;
    scanf("%d", &n);
    maxHeap *heap = (maxHeap *)malloc(sizeof(maxHeap));
    heap->size = 0;
    heap->node = (int *)calloc(n + 1, sizeof(int)); // 빈자리 0, 0번지는 안 씀

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (num == 0)
            printf("%d\n", max_heap_pop(heap));
        else
            max_heap_push(heap, num);
    }

    free(heap->node);
    free(heap);

    return 0;
}

int max_heap_pop(maxHeap *h)
{
    int item, index, child, temp;

    if (h->node[1] == 0) // 힙이 비어있음
        return 0;
    else
    {
        item = h->node[1];
        h->node[1] = h->node[h->size];
        h->node[h->size] = 0;
        h->size--;

        index = 1;
        child = 2;
        while (h->node[index] < h->node[child] || h->node[index] < h->node[child + 1]) // 자식노드와 비교하며 heapify
        {
            temp = h->node[index];
            if (h->node[child] != 0 && h->node[child + 1] != 0)
            {
                if (h->node[child] > h->node[child + 1])
                {
                    h->node[index] = h->node[child];
                    h->node[child] = temp;
                    index = child;
                }
                else
                {
                    h->node[index] = h->node[child + 1];
                    h->node[child + 1] = temp;
                    index = child + 1;
                }
            }
            else
            {
                if (h->node[child] == 0)
                {
                    h->node[index] = h->node[child + 1];
                    h->node[child + 1] = temp;
                    index = child + 1;
                }
                else
                {
                    h->node[index] = h->node[child];
                    h->node[child] = temp;
                    index = child;
                }
            }
            child = index * 2;
        }

        return item;
    }
}
void max_heap_push(maxHeap *h, int data)
{
    int index, parent, temp;

    h->size++;
    h->node[h->size] = data;

    index = h->size;
    parent = index / 2;
    while (index != 1 && h->node[index] > h->node[parent]) // 부모노드와 비교하며 heapify
    {
        temp = h->node[parent];
        h->node[parent] = h->node[index];
        h->node[index] = temp;
        index = parent;
        parent = index / 2;
    }
}