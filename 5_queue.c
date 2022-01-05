#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *elements;
    int front;
    int rear;
    int size;
    int capacity;
};

typedef struct Queue *queue;

queue CreateQueue(int capacity)
{
    // Init a queue with all elements = 0
    queue new_queue = (queue)malloc(sizeof(struct Queue));
    new_queue->elements = (int *)malloc(sizeof(int) * capacity);
    new_queue->capacity = capacity;
    new_queue->front = 0;
    new_queue->size = 0;
    new_queue->rear = -1;
}

int GetQueueSize(queue q)
{
    return q->size;
}

int IsQueueEmpty(queue q)
{
    return q->size == 0;
}

void Enqueue(queue q, int element)
{
    if (q->size == q->capacity)
    {
        printf("Over capacity!");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->elements[q->rear] = element;
    q->size++;
}

int Dequeue(queue q)
{
    if (IsQueueEmpty(q))
    {
        printf("Cannot dequeue from an empty queue!");
        return 0;
    }
    int ret = q->elements[q->front];
    q->elements[q->front] = 0;
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return ret;
}

void PrintQueue(queue q)
{
    for (int i = 0; i < q->capacity; i++)
    {
        printf("%d:\t%d\n", i, q->elements[i]);
    }
    printf("\n");
}

int main()
{
    queue mq = CreateQueue(5);

    Enqueue(mq, 2);
    Enqueue(mq, 5);
    Enqueue(mq, 1);
    // PrintQueue(mq);
    // printf("Size is currently %d\n", GetQueueSize(mq));

    printf("Dequeued element with value %d\n", Dequeue(mq));
    printf("Dequeued element with value %d\n", Dequeue(mq));
    PrintQueue(mq);

    Enqueue(mq, 2);
    Enqueue(mq, 5);
    Enqueue(mq, 9);
    Enqueue(mq, 5);
    Enqueue(mq, 5);
    PrintQueue(mq);

    return EXIT_SUCCESS;
}