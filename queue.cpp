#include "queue.h"

void init(Queue* q) {
    q->front = q->data;
    q->rear = q->data;
}

bool isEmpty(const Queue* q) {
    return q->front == q->rear;
}

bool isFull(const Queue* q) {
    return ((q->rear + 1 - q->data) % MAX) == (q->front - q->data);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw "queue penuh";
    }

    *(q->rear) = value;
    q->rear = q->data + ((q->rear - q->data + 1) % MAX);
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw "queue kosong";
    }

    q->front = q->data + ((q->front - q->data + 1) % MAX);
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

    int idx = (q->rear - q->data - 1 + MAX) % MAX;
    return q->data[idx];
}
