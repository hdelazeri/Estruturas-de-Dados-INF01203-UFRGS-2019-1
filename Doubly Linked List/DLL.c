#include "DLL.h"

Node* Initialize() {
	return NULL;
}

Node* InsertFirst(Node* list, Info data) {
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;

	node->previous = NULL;
	node->next = NULL;

	return node;
}

Node* InsertLast(Node* list, Info data) {
	Node* last = list;

	if (list != NULL) {
		while (last->next != NULL)
			last = last->next;

		Node * node = (Node*)malloc(sizeof(Node));

		node->data = data;

		node->previous = last;
		node->next = NULL;

		last->next = node;
	}
	else {
		list = InsertFirst(list, data);
	}

	return list;
}

Node* InsertMiddle(Node* list, Info data, int position) {
	Node* before = list;

	if (list != NULL && position != 1) {
		for (int i = 1; i < position - 1 && list->next != NULL; i++) {
			before = list->next;
		}

		Node* node = (Node*)malloc(sizeof(Node));

		node->data = data;

		node->next = before->next;
		node->previous = before;

		node->next->previous = node;
		before->next = node;
	}
	else {
		list = InsertFirst(list, data);
	}

	return list;
}

void ListAll(Node* list) {
	Node* aux;

	if (list == NULL) {
		printf("Empty List");
	}
	else {
		for (aux = list; aux != NULL; aux = aux->next)
			printf("%d ", aux->data);
	}
}

void ListAllBackwards(Node* list) {
	Node* aux;

	if (list == NULL) {
		printf("Empty List");
	}
	else {
		Node* last = list;

		while (last->next) {
			last = last->next;
		}

		for (aux = last; aux != NULL; aux = aux->previous)
			printf("%d ", aux->data);
	}
}

Node* Find(Node* list, Info data) {
	Node* aux = list;

	while (aux != NULL && aux->data != data) {
		aux = aux->next;
	}

	return aux;
}

Node* Remove(Node* list, Info data) {
	Node* aux = list;
	Node* before = NULL;

	if (list != NULL) {
		while (aux != NULL && aux->data != data) {
			before = aux;
			aux = aux->next;
		}

		if (aux != NULL) {
			if (before == NULL) {
				list = aux->next;
				list->previous = NULL;
			}
			else {
				before->next = aux->next;
				before->next->previous = aux->previous;
			}

			free(aux);
		}
	}

	return list;
}

Node* Destroy(Node* list) {
	Node* aux;

	while (list != NULL) {
		aux = list;
		list = list->next;

		free(aux);
	}

	free(list);

	return NULL;
}