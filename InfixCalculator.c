#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"	// ConvToRPNExp()
#include "PostCalculator.h"	// EvalRPNExp()

int EvalInfixExp(char exp[])
{
	int len = (int)strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy);		// notation converting.
	ret = EvalRPNExp(expcpy);	// expression evaluating. 

	free(expcpy);
	return ret;
}