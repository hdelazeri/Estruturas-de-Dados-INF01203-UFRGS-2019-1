#include "CDLL.h"

Node* Initialize() {
	return NULL;
}

Node* InsertFirst(Node* list, Info data) {
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;

	node->previous = node;
	node->next = node;

	return node;
}

Node* InsertLast(Node* list, Info data) {
	Node* last = list;

	if (list != NULL) {
		while (last->next != list)
			last = last->next;

		Node * node = (Node*)malloc(sizeof(Node));

		node->data = data;

		node->previous = last;
		node->next = list;

		last->next = node;
		list->previous = node;
	}
	else {
		list = InsertFirst(list, data);
	}

	return list;
}

Node* InsertMiddle(Node * list, Info data, int position) {
	Node* before = list;

	if (list != NULL && position != 1) {
		for (int i = 1; i < position - 1 && list->next != list; i++) {
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

void ListAll(Node * list) {
	Node* aux = list;

	if (list == NULL) {
		printf("Empty List");
	}
	else {
		do {
			printf("%d ", aux->data);
			aux = aux->next;
		} while (aux != list);
	}
}

void ListAllBackwards(Node * list) {
	Node* aux = list->previous;

	if (list == NULL) {
		printf("Empty List");
	}
	else {
		do {
			printf("%d ", aux->data);
			aux = aux->previous;
		} while (aux != list->previous);
	}
}

Node* Find(Node * list, Info data) {
	Node* aux = list;

	while (aux != list && aux->data != data) {
		aux = aux->next;
	}

	return aux;
}

Node* Remove(Node * list, Info data) {
	Node* aux = list;
	int found = 0;

	if (list != NULL) {
		do {
			if (aux->data == data) {
				found = 1;
				break;
			}

			aux = aux->next;
		} while (aux != list);

		if (found) {
			if (aux == list) {
				list->next->previous = list->previous;
				list->previous->next = list->next;

				list = list->next;
			}
			else {
				aux->next->previous = aux->previous;
				aux->previous->next = aux->next;
			}

			free(aux);
		}
	}

	return list;
}

Node* Destroy(Node * list) {
	Node* aux;

	if (list != NULL) {
		aux = list->next;

		while (aux && aux != list) {
			Node* tmp = aux;
			aux = aux->next;
			free(tmp);
		}

		free(list);
	}

	return NULL;
}