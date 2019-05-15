#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef int Info;

struct s_node {
	Info info;
	int balanceFactor;
	struct s_node* left;
	struct s_node* right;
};

typedef struct s_node Node;

Node* Initialize();

Node* Insert(Node* tree, Info data, int* ok);

Node* UnbalancedLeft(Node* tree, int* ok);

Node* UnbalancedRight(Node* tree, int* ok);

void PreFixedLeft(Node* tree);

void CenteredLeft(Node* tree);

void PostFixedLeft(Node* tree);

void PreFixedRight(Node* tree);

void CenteredRight(Node* tree);

void PostFixedRight(Node* tree);

Node* Find(Node* tree, Info data);

int CountNodes(Node* tree);

void PrintFormattedTree(Node* tree, int actualLevel);

Node* Remove(Node* tree, Info data);

Node* Destroy(Node* tree);

Node* RotateRight(Node* tree);

Node* RotateLeft(Node* tree);

Node* RotateLeftRight(Node* tree);

Node* RotateRightLeft(Node* tree);