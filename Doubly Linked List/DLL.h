#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int Info;

struct s_node {
	Info data;
	struct s_node* next;
	struct s_node* previous;
};

typedef struct s_node Node;

Node* Initialize();

Node* InsertFirst(Node* list, Info data);

Node* InsertLast(Node* list, Info data);

Node* InsertMiddle(Node* list, Info data, int position);

void ListAll(Node* list);

void ListAllBackwards(Node* list);

Node* Find(Node* list, Info data);

Node* Remove(Node* list, Info data);

Node* Destroy(Node* list);