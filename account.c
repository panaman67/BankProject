#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

// FIXME: CREATES DANGLING POINTER!!!!!!!!!!!!!!!!
Node CreateNode()
{
	Node temp = (Node)malloc(sizeof(struct Data));
	temp->next = NULL;
	return temp;
}

void AddNode(Node HEAD, Data add)
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

void PrintAccounts(Node HEAD)
{
	Node temp = HEAD->next;

	puts("Fn        | ln       | Balance  ");
	puts("--------------------------------");
	while (temp != NULL)
	{
		printf("%-10s %-10s %10.2lf\n", temp->firstName, temp->lastName, temp->balance);
		temp = temp->next;
	}
}
