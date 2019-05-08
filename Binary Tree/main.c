#include <stdio.h>

#include "BinaryTree.h"

int main() {
	Node* tree;

	tree = Initialize();
	printf("Tree Initialized\n\n");

	tree = InsertRoot(tree, 'a');
	printf("Inserted Root\n\n");

	tree = InsertLeft(tree, 'b', 'a');
	tree = InsertLeft(tree, 'd', 'b');
	tree = InsertRight(tree, 'e', 'b');
	printf("Root Left Subtree Inserted\n\n");

	tree = InsertRight(tree, 'c', 'a');
	tree = InsertLeft(tree, 'f', 'c');
	tree = InsertRight(tree, 'g', 'c');
	printf("Root Right Subtree Inserted\n\n");

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

	printf("\n\nSearch for d: ");
	if (Find(tree, 'd') == NULL) {
		printf("not ");
	}
	printf("found\n");

	printf("Search for h: ");
	if (Find(tree, 'h') == NULL) {
		printf("not ");
	}
	printf("found");

	tree = Destroy(tree);
	printf("\n\nTree Destroyed");

	return 0;
}