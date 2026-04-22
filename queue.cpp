#include "queue.h"

void init(Queue* q) {
    q->front = q->data;
    q->rear = q->data - 1;
}

bool isEmpty(const Queue* q) {
    return q->rear < q->front;
}

bool isFull(const Queue* q) {
    return (q->rear - q->data + 1) == MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw "queue penuh";
    }
    q->rear++;
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong";
    }

    q->front++;
    
    if (q->front > q->rear) {
        q->front = q->data;
        q->rear = q->data - 1;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong";
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong";
    }
    return *(q->rear);
}
