// n번째 큰 수
// min heap

#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap
{
    int *data;
    int size;
} MinHeap;

int N;

void min_heap_push(MinHeap *pq, int data);

int main()
{
    int i, j, input;
    scanf("%d", &N);
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->data = (int *)malloc((N + 1) * sizeof(int)); // 0번지는 빈칸
    minHeap->size = 0;

    for (i = 0; i < N * N; i++) // n^2 만큼 입력
    {
        scanf("%d", &input);
        min_heap_push(minHeap, input);
    }

    printf("%d", minHeap->data[1]);

    free(minHeap->data);
    free(minHeap);

    return 0;
}

void min_heap_push(MinHeap *pq, int data)
{
    int index, parent, child, temp;

    if (pq->size != N) // 힙이 가득차지 않음
    {
        pq->size++;
        pq->data[pq->size] = data;

        index = pq->size;
        parent = index / 2;
        while (index != 1 && pq->data[index] < pq->data[parent]) // 부모노드와 비교하며 heapify
        {
            temp = pq->data[parent];
            pq->data[parent] = pq->data[index];
            pq->data[index] = temp;
            index = parent;
            parent = index / 2;
        }
    }
    else // 힙이 가득 찼으면 최솟값을 삭제하면서 삽입
    {
        if (data > pq->data[1])
        {
            pq->data[1] = data;

            index = 1;
            child = index * 2;
            while ((pq->data[index] > pq->data[child] || pq->data[index] > pq->data[child + 1]) && child <= pq->size) // 자식노드와 비교하며 heapify
            {
                if (child == pq->size) // 왼쪽 자식노드밖에 없는데 오른쪽의 쓰레기 값과 비교하는 것을 방지
                {
                    if (pq->data[index] < pq->data[child])
                        break;
                }

                if (child == pq->size || pq->data[child] < pq->data[child + 1])
                {
                    temp = pq->data[index];
                    pq->data[index] = pq->data[child];
                    pq->data[child] = temp;
                    index = child;
                }
                else if (pq->data[child] > pq->data[child + 1])
                {
                    temp = pq->data[index];
                    pq->data[index] = pq->data[child + 1];
                    pq->data[child + 1] = temp;
                    index = child + 1;
                }
                else
                    break;
                child = index * 2;
            }
        }
    }
}