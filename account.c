#include "account.h"
#include <stdlib.h>
#include <stdio.h>

node createNode()
{
	node temp;
	temp = (node)malloc(sizeof(struct account));
	temp->next = NULL;
	return temp;
}

node addNode(node HEAD, node added)
{
	node temp, p;
	temp = createNode();
	temp->accID = 1234;

	p = HEAD;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
	return HEAD;
}

node deleteNode(node HEAD, int accID)
{
	return NULL;
}

void printAccounts(node HEAD)
{
	int i = 0;
	node temp;
	temp = HEAD;
	while (temp != NULL)
	{
		printf("%d\n", temp->accID);
		temp = temp->next;
	}
}
