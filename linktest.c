#include "account.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Node HEAD, temp;
	HEAD = (Node)malloc(sizeof(struct List));
	HEAD->next = NULL;
	HEAD->accID = 44444;

	AddNode(HEAD, NULL);

	printAccounts(HEAD);
	return 0;
}
