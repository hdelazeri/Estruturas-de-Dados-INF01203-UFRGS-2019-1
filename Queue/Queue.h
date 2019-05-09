#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int Info;

struct s_queue {
	Info data;
	struct s_queue* tail;
};

typedef struct s_queue QueueElement;

typedef struct {
	QueueElement* first;
	QueueElement* last;
} Queue;

Queue* Initialize(Queue* queue);

int Empty(Queue* queue);

int Enqueue(Queue** queue, Info data);

int Dequeue(Queue** queue, Info* data);

Info First(Queue* queue);

void Destroy(Queue** queue);