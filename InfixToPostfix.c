#include <string.h>	// memset()
#include <stdlib.h>
#include <ctype.h>	// isdigit()
#include "ListBaseStack.h"

int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = (int)strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);	// space for converted expression.

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);	// set the memory space to '0'.
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))			// if digit,
		{
			convExp[idx++] = tok;	// directly saves it to the expression.
		}
		else						// if operator,
		{
			switch (tok)
			{
			case '(':
				SPush(&stack, tok);
				break;

			case ')':
				while (1)			// remove all stack elements until meeting '('.
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) &&
					WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);	// remove all high-precedence elements.

				SPush(&stack, tok);					// and then push 'tok'.
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))				// remaining operators,
		convExp[idx++] = SPop(&stack);		// popped to the expression.

	strcpy(exp, convExp);
	free(convExp);
}