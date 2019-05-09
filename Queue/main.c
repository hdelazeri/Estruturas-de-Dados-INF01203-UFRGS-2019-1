#include <stdio.h>

#include "Queue.h"

int main() {
	Queue* queue;
	Info first;
	Info dequeued;

	queue = Initialize(&queue);
	printf("Queue Initialized\n\n");

	if (Enqueue(&queue, 1)) {
		printf("Element Enqueued\n");
	}
	else {
		printf("Failed to Enqueued\n");
	}

	if (Enqueue(&queue, 2)) {
		printf("Element Enqueued\n");
	}
	else {
		printf("Failed to Enqueued\n");
	}

	if (Enqueue(&queue, 3)) {
		printf("Element Enqueued\n");
	}
	else {
		printf("Failed to Enqueued\n");
	}

	if (Enqueue(&queue, 4)) {
		printf("Element Enqueued\n");
	}
	else {
		printf("Failed to Enqueued\n");
	}

	printf("Elements Enqueued\n\n");

	first = First(queue);
	printf("First element of the queue: %d\n\n", first);

	if (Dequeue(&queue, &dequeued)) {
		printf("Element Dequeued: %d\n\n", dequeued);
	}
	else {
		printf("Failed to Dequeue\n\n");
	}

	if (Dequeue(&queue, &dequeued)) {
		printf("Element Dequeued: %d\n\n", dequeued);
	}
	else {
		printf("Failed to Dequeue\n\n");
	}

	Destroy(&queue);
	printf("Queue Destroyed");

	return 0;
}