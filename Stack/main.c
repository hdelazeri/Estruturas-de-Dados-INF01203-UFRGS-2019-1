#include <stdio.h>

#include "Stack.h"

int main() {
	Stack* stack;
	Stack* data;
	Info popped;

	stack = Initialize();
	printf("Stack Initialized\n\n");

	stack = Push(stack, 1);
	stack = Push(stack, 2);
	stack = Push(stack, 3);
	stack = Push(stack, 4);
	printf("Elements Pushed\n\n");

	data = Top(stack);
	printf("Element on the top: %d\n\n", data->data);

	printf("Stack: ");
	ListAll(stack);
	printf("\n\n");

	if (Pop(&stack, &popped)) {
		printf("Element Popped: %d\n\n", popped);
	}
	else {
		printf("Failed to Pop\n\n");
	}

	if (Pop(&stack, &popped)) {
		printf("Element Popped: %d\n\n", popped);
	}
	else {
		printf("Failed to Pop\n\n");
	}

	stack = Destroy(stack);
	printf("Stack Destroyed");

	return 0;
}