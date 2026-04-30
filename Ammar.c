#include <stdio.h>
#include <string.h>

#define CAPACITY 20

typedef struct {
    char data[CAPACITY];
    int write_index;
    int read_index;
    int current_size;
} CircularQueue;

void setupQueue(CircularQueue *q) {
    q->write_index = 0;
    q->read_index = 0;
    q->current_size = 0;
}

int queueIsEmpty(const CircularQueue *q) {
    return q->current_size == 0;
}

int queueIsFull(const CircularQueue *q) {
    return q->current_size == CAPACITY;
}

void addToQueue(CircularQueue *q, char value) {
    if (queueIsFull(q)) {
        printf("Overflow!\n");
        return;
    }
    q->data[q->write_index] = value;
    q->write_index = (q->write_index + 1) % CAPACITY;
    q->current_size++;
}

char removeFromQueue(CircularQueue *q) {
    if (queueIsEmpty(q)) {
        printf("Underflow!\n");
        return '\0';
    }
    char value = q->data[q->read_index];
    q->read_index = (q->read_index + 1) % CAPACITY;
    q->current_size--;
    return value;
}

int main() {
    CircularQueue q;
    setupQueue(&q);

    char name[50];
    printf("Enter your name: ");
    scanf("%49s", name);

    strcat(name, "CE-ESY");

    for (int i = 0; i < strlen(name); i++) {
        addToQueue(&q, name[i]);
    }

    while (!queueIsEmpty(&q)) {
        printf("%c", removeFromQueue(&q));
    }

    printf("\n");
    return 0;
}
