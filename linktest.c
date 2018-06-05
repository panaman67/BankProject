#include "account.h"
#include <stdio.h>

int main()
{
	node HEAD, temp;
	HEAD->next = NULL;

	//temp = createNode();
	bool stat = addNode(HEAD, temp);
	printf("%d\n", stat);
	return 0;
}
