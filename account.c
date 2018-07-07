#include "account.h"
#include <stdlib.h>
#include <stdio.h>

Node CreateNode()
{
	Node temp;
	temp = (Node)malloc(sizeof(struct data));
	temp->next = NULL;
	return temp;
}

void AddNode(Node head, struct node toAdd)
{
	node new_node, last;
	new_node = createNode();

	last = *head;
	new_node->account = toAdd;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return;
}

void DeleteNode(node HEAD, int accID)
{
	return;
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
