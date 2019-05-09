#include "CSLL.h"

Node* Initialize() {
	return NULL;
}

Node* InsertFirst(Node* list, Info data) {
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;

	node->next = node;

	return node;
}

Node* InsertLast(Node* list, Info data) {
	Node* last = list;

	if (list != NULL) {
		while (last->next != list)
			last = last->next;

		Node* node = (Node*)malloc(sizeof(Node));

		node->data = data;

		node->next = list;

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
		for (int i = 1; i < position - 1 && list->next != list; i++) {
			before = list->next;
		}

		Node* node = (Node*)malloc(sizeof(Node));

		node->data = data;

		node->next = before->next;
		before->next = node;
	}
	else {
		list = InsertFirst(list, data);
	}

	return list;
}

void ListAll(Node* list)
{
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

Node* Find(Node* list, Info data) {
	Node* aux = list;
	Node* found = NULL;

	if (list != NULL) {
		do {
			if (aux->data == data) {
				found = aux;
				break;
			}

			aux = aux->next;
		} while (aux != list);
	}

	return found;
}

Node* Remove(Node* list, Info data) {
	Node* before = NULL;
	Node* aux = list;
	int found = 0;

	if (list != NULL) {
		do {
			if (aux->data == data) {
				found = 1;
				break;
			}

			before = aux;
			aux = aux->next;
		} while (aux != list);

		if (found) {
			if (before == NULL) {
				Node* last = list;

				while (last->next != list)
					last = last->next;

				list = aux->next;
				last->next = list;
			}
			else {
				before->next = aux->next;
			}

			free(aux);
		}
	}

	return list;
}

Node* Destroy(Node* list) {
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