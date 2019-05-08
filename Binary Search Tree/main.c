#include <stdio.h>
#include "BST.h"

int main() {
	Node* tree;

	tree = Initialize();
	printf("Tree Initialized\n\n");

	tree = Insert(tree, 8);
	tree = Insert(tree, 4);
	tree = Insert(tree, 9);
	tree = Insert(tree, 2);
	tree = Insert(tree, 6);
	tree = Insert(tree, 1);
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

	printf("\n\nSearch for 9: ");
	if (Find(tree, 9) == NULL) {
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

	Remove(tree, 6);
	printf("\n\nFormatted tree after removing node 6:\n");
	PrintFormattedTree(tree, 1);

	Remove(tree, 4);
	printf("\n\nFormatted tree after removing node 4:\n");
	PrintFormattedTree(tree, 1);

	Remove(tree, 8);
	printf("\n\nFormatted tree after removing node 8:\n");
	PrintFormattedTree(tree, 1);

	tree = Destroy(tree);
	printf("\n\nTree Destroyed");

	return 0;
}