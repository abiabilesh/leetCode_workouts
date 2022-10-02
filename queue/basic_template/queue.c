#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queue{
	long front;
	long rear;
	long size;
	long capacity;
	long  *data;
};

typedef struct Queue Queue;

bool is_queue_empty(Queue* q){
	return q->size == 0;
}

bool is_queue_full(Queue* q){
	return (q->size == (q->capacity));
}

long enqueue(Queue *q, long val){
	if(is_queue_full(q)){
		printf("Queue is full!\n");
		return -1;
	}
	
	printf("Enqueuing q @ %ld with %ld\n", q->rear, val);
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % q->capacity;
	q->size++;

	return q->size;
}

long dequeue(Queue* q){
	long temp = INT_MIN;
	if(is_queue_empty(q)){
		printf("Queue is empty!\n");
		return -1;
	}

	temp = q->data[q->front];
	printf("Dequeuing q @ %ld with %ld\n", q->front, temp);

	q->front = (q->front + 1) % q->capacity;
	q->size--;

	return temp;
}

Queue* create_queue(long capacity){
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = 0;
	queue->size = 0;
	queue->rear = 0;

	queue->data = (long*)malloc(capacity * sizeof(long));
	return queue;
}

void main(){
	Queue *q;

	q = create_queue(40);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	dequeue(q);
	enqueue(q, 4);
	dequeue(q);
	dequeue(q);
	enqueue(q, 5);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);

	return;
}




