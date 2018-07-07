#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<stdbool.h>

struct personal
{
	char*            firstName;
	char*            lastName;
	char*            phoneNumber;
	char*            city;
	char*            state;
};

struct account
{
	bool             isAdmin;
	int              accID;
	char*            password;
	float            balance;
};

typedef struct Node
{
	struct personal  pers;      
	struct account   info;
	struct Node*     next;
} Node;

typedef Node* List;

Node createNode();
void AddNode(List head, Node toAdd);
void DeleteNode(List head, int accID);
void printAccounts(Node head);


#endif
