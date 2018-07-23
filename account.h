#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct Data
{
	struct Data*  next;
	char          firstName[10];
	char          lastName[10];
	char          phoneNumber[10];
	char          city[10];
	char          password[10];
	double        balance;
	int           accID;
	char          state[10];
} Data;

typedef Data* Node;
typedef Node* List;

Node CreateNode();
Node CreateNodeNew();
void AddNode(Node HEAD, Data newNode);
void AddNodeNew(List list, Node add);
void PrintAccounts(Node HEAD);

#endif
