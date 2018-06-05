#include "account.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	node HEAD, temp;
	HEAD = (node)malloc(sizeof(struct account));
	HEAD->next = NULL;
	HEAD->accID = 44444;

	//temp = createNode();
	HEAD = addNode(HEAD, NULL);
	//addNode(HEAD, NULL);
	//printf("%d\n", stat);
	printAccounts(HEAD);
	return 0;
}
