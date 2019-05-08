#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef char Info;

struct s_node {
	Info info;
	struct s_node* left;
	struct s_node* right;
};

typedef struct s_node Node;

Node* Initialize();

Node* InsertRoot(Node* tree, Info data);

Node* InsertLeft(Node* tree, Info data, Info parentKey);

Node* InsertRight(Node* tree, Info data, Info parentKey);

Node* Find(Node* tree, Info data);

void PreFixedLeft(Node* tree);

void CenteredLeft(Node* tree);

void PostFixedLeft(Node* tree);

void PreFixedRight(Node* tree);

void CenteredRight(Node* tree);

void PostFixedRight(Node* tree);

Node* Destroy(Node* tree);