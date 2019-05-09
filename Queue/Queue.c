#include "Queue.h"

Queue* Initialize(Queue* queue) {
	queue = (Queue*)malloc(sizeof(Queue));

	if (queue != NULL) {
		queue->first = NULL;
		queue->last = NULL;
	}

	return queue;
}

int Empty(Queue* queue) {
	if (queue == NULL) {
		printf("Queue not allocated in memory");
		return -1;
	}
	else {
		if (queue->first == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

int Enqueue(Queue** queue, Info data) {
	if (*queue) {
		QueueElement* element = (QueueElement*)malloc(sizeof(QueueElement));

		element->data = data;

		element->tail = NULL;

		if (Empty(*queue))
			(*queue)->first = element;
		else 
			(*queue)->last->tail = element;

		(*queue)->last = element;

		return 1;
	}
	else {
		return 0;
	}
}

int Dequeue(Queue** queue, Info * data) {
	if (*queue) {
		if (!Empty(*queue)) {
			QueueElement* element = (*queue)->first;

			*data = (*queue)->first->data;

			(*queue)->first = (*queue)->first->tail;

			free(element);

			if ((*queue)->first == NULL)
				(*queue)->last == NULL;

			return 1;
		}

		return 1;
	}
	else {
		return 0;
	}
}

Info First(Queue * queue) {
	if (!Empty(queue))
		return queue->first->data;
	else
		return 0;
}

void Destroy(Queue** queue) {
	QueueElement* aux;

	if (*queue) {
		while (!Empty(*queue)) {
			aux = (*queue)->first;
			(*queue)->first = (*queue)->first->tail;

			free(aux);
		}
		
		free(*queue);

		*queue = NULL;
	}
}