#include "account.h"
#include <stdlib.h>

node createNode()
{
	node temp;

	return temp;
}

bool addNode(node HEAD, node added)
{
	node temp = HEAD;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = added;
	return true;
}

bool deleteNode(node HEAD, int accID)
{
	return false;
}


