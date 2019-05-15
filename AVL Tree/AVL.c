#include "AVL.h"

Node* Initialize() {
	return NULL;
}

Node* Insert(Node* tree, Info data, int* ok) {
	if (tree == NULL) {
		tree = (Node*)malloc(sizeof(Node));

		tree->info = data;

		tree->left = NULL;
		tree->right = NULL;

		tree->balanceFactor = 0;

		*ok = 1;
	}
	else {
		if (data < tree->info) {
			tree->left = Insert(tree->left, data, ok);
			if (*ok) {
				switch (tree->balanceFactor) {
				case -1:
					tree->balanceFactor = 0;
					*ok = 0;
					break;
				case 0:
					tree->balanceFactor = 1;
					break;
				case 1:
					tree = UnbalancedLeft(tree, ok);
					break;
				}
			}
		}
		else {
			tree->right = Insert(tree->right, data, ok);
			if (*ok) {
				switch (tree->balanceFactor) {
				case 1:
					tree->balanceFactor = 0;
					*ok = 0;
					break;
				case 0:
					tree->balanceFactor = 1;
					break;
				case -1:
					tree = UnbalancedRight(tree, ok);
					break;
				}
			}
		}
	}

	return tree;
}

Node* UnbalancedLeft(Node* tree, int* ok) {
	Node* node;

	node = tree->left;

	if (node->balanceFactor == 1)
		tree = RotateRight(tree);
	else
		tree = RotateLeftRight(tree);

	tree->balanceFactor = 0;
	*ok = 0;

	return tree;
}

Node* UnbalancedRight(Node* tree, int* ok) {
	Node* node;

	node = tree->right;

	if (node->balanceFactor == -1)
		tree = RotateLeft(tree);
	else
		tree = RotateRightLeft(tree);

	tree->balanceFactor = 0;
	*ok = 0;

	return tree;
}

void PreFixedLeft(Node * tree) {
	if (tree != NULL) {
		printf("%d ", tree->info);
		PreFixedLeft(tree->left);
		PreFixedLeft(tree->right);
	}
}

void CenteredLeft(Node * tree) {
	if (tree != NULL) {
		CenteredLeft(tree->left);
		printf("%d ", tree->info);
		CenteredLeft(tree->right);
	}
}

void PostFixedLeft(Node * tree) {
	if (tree != NULL) {
		PostFixedLeft(tree->left);
		PostFixedLeft(tree->right);
		printf("%d ", tree->info);
	}
}

void PreFixedRight(Node * tree) {
	if (tree != NULL) {
		printf("%d ", tree->info);
		PreFixedRight(tree->right);
		PreFixedRight(tree->left);
	}
}

void CenteredRight(Node * tree) {
	if (tree != NULL) {
		CenteredRight(tree->right);
		printf("%d ", tree->info);
		CenteredRight(tree->left);
	}
}

void PostFixedRight(Node * tree) {
	if (tree != NULL) {
		PostFixedRight(tree->right);
		PostFixedRight(tree->left);
		printf("%d ", tree->info);
	}
}

Node* Find(Node * tree, int data) {
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

Node* Remove(Node * tree, Info data) {
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

Node* RotateRight(Node * tree) {
	printf("RotateRight\n");
	Node* node;

	node = tree->left;
	tree->left = node->right;
	node->right = tree;

	tree->balanceFactor = 0;

	tree = node;

	return tree;
}

Node* RotateLeft(Node * tree) {
	printf("RotateLeft\n");
	Node* node;

	node = tree->right;
	tree->right = node->left;
	node->left = tree;

	tree->balanceFactor = 0;

	tree = node;

	return tree;
}

Node* RotateLeftRight(Node * tree) {
	printf("RotateLeftRight\n");
	Node* node1, * node2;

	node1 = tree->left;
	node2 = node1->right;

	node1->right = node2->left;
	node2->left = node1;
	tree->left = node2->right;
	node2->right = tree;

	if (node2->balanceFactor == 1)
		tree->balanceFactor = -1;
	else
		tree->balanceFactor = 0;

	if (node2->balanceFactor == -1)
		node1->balanceFactor = 1;
	else
		node1->balanceFactor = 0;

	tree = node2;

	return tree;
}

Node * RotateRightLeft(Node * tree) {
	printf("RotateRightLeft\n");
	Node* node1, * node2;

	node1 = tree->right;
	node2 = node1->left;

	node1->left = node2->right;
	node2->right = node1;
	tree->right = node2->left;
	node2->left = tree;

	if (node2->balanceFactor == 1)
		tree->balanceFactor = -1;
	else
		tree->balanceFactor = 0;

	if (node2->balanceFactor == -1)
		node1->balanceFactor = 1;
	else
		node1->balanceFactor = 0;

	tree = node2;

	return tree;
}

