#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	// Initializing Stack //
	Stack stack;
	StackInit(&stack);

	// Pushing data //
	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	// Popping data //
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}