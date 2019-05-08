#include "BST.h"

Node* Initialize() {
	return NULL;
}

Node* Insert(Node* tree, Info data) {
	if (tree == NULL) {
		tree = (Node*)malloc(sizeof(Node));

		tree->info = data;

		tree->left = NULL;
		tree->right = NULL;
	}
	else {
		if (data < tree->info)
			tree->left = Insert(tree->left, data);
		else
			tree->right = Insert(tree->right, data);
	}

	return tree;
}

void PreFixedLeft(Node* tree) {
	if (tree != NULL) {
		printf("%d ", tree->info);
		PreFixedLeft(tree->left);
		PreFixedLeft(tree->right);
	}
}

void CenteredLeft(Node* tree) {
	if (tree != NULL) {
		CenteredLeft(tree->left);
		printf("%d ", tree->info);
		CenteredLeft(tree->right);
	}
}

void PostFixedLeft(Node* tree) {
	if (tree != NULL) {
		PostFixedLeft(tree->left);
		PostFixedLeft(tree->right);
		printf("%d ", tree->info);
	}
}

void PreFixedRight(Node* tree) {
	if (tree != NULL) {
		printf("%d ", tree->info);
		PreFixedRight(tree->right);
		PreFixedRight(tree->left);
	}
}

void CenteredRight(Node* tree) {
	if (tree != NULL) {
		CenteredRight(tree->right);
		printf("%d ", tree->info);
		CenteredRight(tree->left);
	}
}

void PostFixedRight(Node* tree) {
	if (tree != NULL) {
		PostFixedRight(tree->right);
		PostFixedRight(tree->left);
		printf("%d ", tree->info);
	}
}

Node* Find(Node* tree, int data) {
	if (tree == NULL) {
		return NULL;
	}
	else {
		if (tree->info == data)
			return tree;
		else
			if (tree->info > data)
				return Find(tree->left, data);
			else
				return Find(tree->right, data);
	}
}

int CountNodes(Node * tree) {
	if (tree == NULL)
		return 0;

	return 1 + CountNodes(tree->left) + CountNodes(tree->right);
}

void PrintFormattedTree(Node * tree, int actualLevel) {
	if (tree != NULL) {
		for (int i = 0; i < actualLevel; i++)
		{
			printf("=");
		}

		printf("%d\n", tree->info);

		PrintFormattedTree(tree->left, actualLevel + 1);
		PrintFormattedTree(tree->right, actualLevel + 1);
	}
}

Node* Remove(Node* tree, Info data) {
	if (tree != NULL) {
		if (tree->info == data) {
			// Case 1: No Subtree - Just destroy
			if (tree->left == NULL && tree->right == NULL) {
				free(tree);

				return NULL;
			}
			else {
				// Case 2: One Subtree - The first child takes the parent position
				if (tree->left != NULL && tree->right == NULL || tree->left == NULL && tree->right != NULL) {
					Node* firstChild;

					if (tree->left != NULL) 
						firstChild = tree->left;
					else 
						firstChild = tree->right;
					
					free(tree);

					return firstChild;
				}
				else {
					// Case 3 - Two subtrees - The highest value of the left tree takes the position of the removed node
					Node* highest = tree->left;

					while (highest->right)
					{
						highest = highest->right;
					}

					tree->info = highest->info;

					tree->left = Remove(tree->left, highest->info);

					return tree;
				}
			}
		}
		else {
			tree->left = Remove(tree->left, data);
			tree->right = Remove(tree->right, data);
			return tree;
		}
	}
	else {
		return NULL;
	}
}

Node* Destroy(Node * tree) {
	if (tree != NULL) {
		Destroy(tree->left);
		Destroy(tree->right);

		free(tree);

		return NULL;
	}
}