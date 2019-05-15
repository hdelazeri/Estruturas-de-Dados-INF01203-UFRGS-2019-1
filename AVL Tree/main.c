#include <stdio.h>
#include "AVL.h"

int main() {
	Node* tree;
	int ok;

	tree = Initialize();
	printf("Tree Initialized\n\n");

	tree = Insert(tree, 50, &ok);
	tree = Insert(tree, 40, &ok);
	tree = Insert(tree, 30, &ok);
	tree = Insert(tree, 45, &ok);
	tree = Insert(tree, 47, &ok);
	tree = Insert(tree, 55, &ok);
	tree = Insert(tree, 56, &ok);
	tree = Insert(tree, 1, &ok);
	tree = Insert(tree, 2, &ok);
	tree = Insert(tree, 3, &ok);
	printf("All Nodes Inserted\n\n");

	printf("Pre Fixed Left: ");
	PreFixedLeft(tree);

	printf("\nCentered Left: ");
	CenteredLeft(tree);

	printf("\nPost Fixed Left: ");
	PostFixedLeft(tree);

	printf("\nPre Fixed Right: ");
	PreFixedRight(tree);

	printf("\nCentered Right: ");
	CenteredRight(tree);

	printf("\nPost Fixed Right: ");
	PostFixedRight(tree);

	printf("\n\nSearch for 56: ");
	if (Find(tree, 56) == NULL) {
		printf("not ");
	}
	printf("found\n");

	printf("Search for 7: ");
	if (Find(tree, 7) == NULL) {
		printf("not ");
	}
	printf("found");

	printf("\n\nNumber of nodes in tree: %d", CountNodes(tree));

	printf("\n\nFormatted Tree:\n");
	PrintFormattedTree(tree, 1);

	tree = Destroy(tree);
	printf("\n\nTree Destroyed");

	return 0;
}