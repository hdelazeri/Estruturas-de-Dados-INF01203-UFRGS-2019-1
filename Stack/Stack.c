#include "Stack.h"

Stack* Initialize() {
	return NULL;
}

int Empty(Stack* stack) {
	if (stack == NULL)
		return 1;

	return 0;
}

Stack* Push(Stack* stack, Info data) {
	Stack* node = (Stack*)malloc(sizeof(Stack));

	node->data = data;

	node->head = stack;

	return node;
}

int Pop(Stack** stack, Info* data) {
	Stack* aux;

	if (Empty(*stack)) {
		return 0;
	}
	else {
		*data = (*stack)->data;
		
		aux = *stack;
		*stack = (*stack)->head;

		free(aux);

		return 1;
	}
}

Stack* Top(Stack* stack) {
	if (!Empty(stack))
		return stack;
	else
		return NULL;
}

Stack* Destroy(Stack* stack) {
	Stack* aux;

	while (stack != NULL) {
		aux = stack;
		stack = stack->head;

		free(aux);
	}

	free(stack);

	return NULL;
}

void ListAll(Stack* stack) {
	Stack* aux;

	if (Empty(stack)) {
		printf("Empty Stack");
	}
	else {
		for (aux = stack; aux != NULL; aux = aux->head)
			printf("%d ", aux->data);
	}
}