#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = (int)strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
		{
			SPush(&stack, tok - '0');	// char is converted to integer.
		}
		else
		{
			op2 = SPop(&stack);		// op2 first!
			op1 = SPop(&stack);		// following op1.

			switch (tok)
			{						// re-push the operation result.
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1*op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	return SPop(&stack);
}