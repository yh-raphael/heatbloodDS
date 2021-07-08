#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// Defines and initialize DB L.L. //
	List list;
	int data;
	ListInit(&list);

	// Stores 8 data //
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	// Prints stored data //
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// Moving right.
		while (LNext(&list, &data))
			printf("%d ", data);

		// Moving left.
		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}