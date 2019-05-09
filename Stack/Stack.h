#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int Info;

struct s_stack {
	Info data;
	struct s_stack* head;
};

typedef struct s_stack Stack;

Stack* Initialize();

int Empty(Stack* stack);

Stack* Push(Stack* stack, Info data);

int Pop(Stack** stack, Info* data);

Stack* Top(Stack* stack);

Stack* Destroy(Stack* stack);

void ListAll(Stack* stack);