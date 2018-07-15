#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "account.h"

Node CreateNode()
{
	Node temp = (Node)malloc(sizeof(struct List));
	temp->next = NULL;
	return temp;
}

void AddNode(Node HEAD, List add)
{
	Node temp, last;
	temp = CreateNode();
	last = HEAD;

	strcpy(temp->firstName, add.firstName);
	strcpy(temp->lastName, add.lastName);
	strcpy(temp->city, add.city);
	strcpy(temp->state, add.state);
	strcpy(temp->phoneNumber, add.phoneNumber);
	strcpy(temp->password, add.password);
	temp->accID = add.accID;
	temp->balance = add.balance;

	while (last->next != NULL)
		last = last->next;
	last->next = temp;
}

void DeleteNode(Node HEAD, int accID)
{
	// TODO
}

void PrintAccounts(Node HEAD)
{
	Node temp = HEAD;
	while (temp != NULL)
	{
		printf("%d\n", temp->accID);
		temp = temp->next;
	}
}
