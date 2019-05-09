#include <stdio.h>

#include "CDLL.h"

int main() {
	Node* list;

	list = Initialize();
	printf("List Initialized\n\n");

	list = InsertFirst(list, 1);
	printf("Inserted First\n\n");

	list = InsertLast(list, 4);
	printf("Inserted Last\n\n");

	list = InsertMiddle(list, 3, 2);
	list = InsertMiddle(list, 2, 2);
	printf("Inserted Middle\n\n");

	printf("List: ");
	ListAll(list);
	printf("\n\n");

	printf("List Backwards: ");
	ListAllBackwards(list);
	printf("\n\n");

	printf("Search for 2: ");
	if (Find(list, 2) == NULL) {
		printf("not ");
	}
	printf("found\n");

	printf("Search for 7: ");
	if (Find(list, 7) == NULL) {
		printf("not ");
	}
	printf("found\n\n");

	list = Remove(list, 1);
	list = Remove(list, 3);
	printf("1 and 3 removed\n\n");

	list = Destroy(list);
	printf("List Destroyed");

	return 0;
}