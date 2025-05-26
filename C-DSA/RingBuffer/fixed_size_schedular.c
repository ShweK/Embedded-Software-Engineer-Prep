#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_TASKS 8

typedef struct {
    uint8_t buffer[MAX_TASKS];
    int head;  // next write
    int tail;  // next read
    int count;
} TaskQueue;

void initQueue(TaskQueue* q){
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

bool isFull(TaskQueue* q){
    return q->count == MAX_TASKS;
}

bool isEmpty(TaskQueue* q){
    return q->count == 0;
}

bool enqueue(TaskQueue* q, uint8_t taskId){
    if (isFull(q)) return false;

    q->buffer[q->head] = taskId;
    q->head = (q->head + 1) % MAX_TASKS;
    q->count++;
    return true;
}

bool dequeue(TaskQueue* q, uint8_t* taskId){
    if (isEmpty(q)) return false;

    *taskId = q->buffer[q->tail];
    q->tail = (q->tail + 1) % MAX_TASKS;
    q->count--;
    return true;
}

void printQueue(TaskQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    int index = q->tail;  // start from the read pointer
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->buffer[index]);
        index = (index + 1) % MAX_TASKS;
    }
    printf("\n");
}

int main(){
    TaskQueue q;
initQueue(&q);

enqueue(&q, 10);
enqueue(&q, 20);
enqueue(&q, 30);
printQueue(&q);    // Output: 10 20 30

uint8_t t;
dequeue(&q, &t);   // t = 10
printQueue(&q);    // Output: 20 30
}