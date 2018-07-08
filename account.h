#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<stdbool.h>

typedef struct List
{
	struct List*  next;
	char*         firstName;
	char*         lastName;
	char*         phoneNumber;
	char*         city;
	char*         state;
	char*         password;
	int           accID;
	float         balance;
	bool          isAdmin;
} List;

typedef List* Node;

Node CreateNode();
void AddNode(Node head, int accID);
void printAccounts(Node head);

#endif
