#include "account.h"
#include <stdlib.h>
#include <stdio.h>

Node CreateNode()
{
	Node temp;
	temp = (Node)malloc(sizeof(struct List));
	temp->next = NULL;
	return temp;
}

void AddNode(Node HEAD, int accID)
{
	Node temp, last;

	temp = CreateNode();
	last = HEAD;

	temp->accID = accID;
	temp->next = NULL;

	if (HEAD == NULL)
	{
		HEAD = temp;
		return;
	}

	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	return;
}

void DeleteNode(Node HEAD, int accID)
{
	return;
}

void printAccounts(Node HEAD)
{
	Node temp;
	temp = HEAD;
	while (temp != NULL)
	{
		printf("%d\n", temp->accID);
		temp = temp->next;
	}
}
