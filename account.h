#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdbool.h>

typedef struct List
{
	struct List*  next;
	char          firstName[10];
	char          lastName[10];
	char          phoneNumber[10];
	char          city[10];
	char          password[10];
	double        balance;
	int           accID;
	char          state[10];
} List;

struct Admin
{
	int ID;
	char password[10];
};

typedef List* Node;

Node CreateNode();
void AddNodeTest(Node HEAD, int accID);
void AddNode(Node HEAD, Node newNode);
void PrintAccounts(Node head);

#endif
