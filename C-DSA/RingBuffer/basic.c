#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 8

typedef struct {
    uint8_t data[BUFFER_SIZE];
    int head;   // Write index
    int tail;   // Read index
    int size;   // Count of valid entries
} RingBuffer;

void rb_init(RingBuffer *rb){
    rb->head = 0;
    rb->tail = 0;
    rb->size = 0;
}

bool rb_is_empty(RingBuffer *rb){
    return rb->size == 0;
}

bool rb_is_full(RingBuffer *rb){
    return rb->size == BUFFER_SIZE;
}

void rb_push(RingBuffer *rb, uint8_t value){
    rb->data[rb->head] = value;
    rb->head = (rb->head + 1) % BUFFER_SIZE;

    if (rb->size == BUFFER_SIZE) {
        // Overwrite behavior
        rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    } else {
        rb->size++;
    }
}

bool rb_pop(RingBuffer *rb, uint8_t *value){
    if (rb_is_empty(rb)) return false;

    *value = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->size--;
    return true;
}

void printQueue(RingBuffer *rb){
    printf("Queue: ");
    int count = rb->size;
    int idx = rb->tail;
    while (count--) {
        printf("%d ", rb->data[idx]);
        idx = (idx + 1) % BUFFER_SIZE;
    }
    printf("\n");
}

int main() {
    RingBuffer rb;
    rb_init(&rb);

    printf("Pushing values 1 to 8...\n");
    for (uint8_t i = 1; i <= 8; i++) {
        rb_push(&rb, i);
    }
    printQueue(&rb);

    printf("Popping 3 values...\n");
    for (int i = 0; i < 3; i++) {
        uint8_t val;
        if (rb_pop(&rb, &val)) {
            printf("Popped: %d\n", val);
        }
    }
    printQueue(&rb);

    printf("Pushing values 9, 10...\n");
    rb_push(&rb, 9);
    rb_push(&rb, 10);
    printQueue(&rb);

    printf("Popping all remaining values...\n");
    while (!rb_is_empty(&rb)) {
        uint8_t val;
        rb_pop(&rb, &val);
        printf("Popped: %d\n", val);
    }
    printQueue(&rb);

    return 0;
}