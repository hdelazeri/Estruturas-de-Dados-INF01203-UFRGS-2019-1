#include "BinaryTree.h"

Node* Initialize() {
	return NULL;
}

Node* InsertRoot(Node* tree, Info data)
{
	if (tree == NULL) {
		tree = (Node*)malloc(sizeof(Node));

		tree->info = data;

		tree->left = NULL;
		tree->right = NULL;
	}

	return tree;
}

Node* InsertLeft(Node* tree, Info data, Info parentKey)
{
	Node* parent;
	Node* node;

	parent = Find(tree, parentKey);

	if (parent != NULL) {
		if (parent->left == NULL) {
			node = (Node*)malloc(sizeof(Node));

			node->info = data;

			node->left = NULL;
			node->right = NULL;

			parent->left = node;
		}
		else {
			printf("The node already have a left subtree\n");
		}
	}

	return tree;
}

Node* InsertRight(Node* tree, Info data, Info parentKey)
{
	Node* parent;
	Node* node;

	parent = Find(tree, parentKey);

	if (parent != NULL) {
		if (parent->right == NULL) {
			node = (Node*)malloc(sizeof(Node));

			node->info = data;

			node->left = NULL;
			node->right = NULL;

			parent->right = node;
		}
		else {
			printf("The node already have a right subtree\n");
		}
	}

	return tree;
}

Node* Find(Node * tree, Info data)
{
	Node* found = NULL;

	if (tree != NULL) {
		if (tree->info == data)
			found = tree;
		else {
			found = Find(tree->left, data);

			if (!found)
				found = Find(tree->right, data);
		}
	}

	return found;
}

void PreFixedLeft(Node* tree) {
	if (tree != NULL) {
		printf("%c ", tree->info);
		PreFixedLeft(tree->left);
		PreFixedLeft(tree->right);
	}
}

void CenteredLeft(Node* tree) {
	if (tree != NULL) {
		CenteredLeft(tree->left);
		printf("%c ", tree->info);
		CenteredLeft(tree->right);
	}
}

void PostFixedLeft(Node* tree) {
	if (tree != NULL) {
		PostFixedLeft(tree->left);
		PostFixedLeft(tree->right);
		printf("%c ", tree->info);
	}
}

void PreFixedRight(Node* tree) {
	if (tree != NULL) {
		printf("%c ", tree->info);
		PreFixedRight(tree->right);
		PreFixedRight(tree->left);
	}
}

void CenteredRight(Node* tree) {
	if (tree != NULL) {
		CenteredRight(tree->right);
		printf("%c ", tree->info);
		CenteredRight(tree->left);
	}
}

void PostFixedRight(Node* tree) {
	if (tree != NULL) {
		PostFixedRight(tree->right);
		PostFixedRight(tree->left);
		printf("%c ", tree->info);
	}
}

Node* Destroy(Node* tree) {
	if (tree != NULL) {
		Destroy(tree->left);
		Destroy(tree->right);

		free(tree);

		return NULL;
	}
}