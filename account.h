#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<stdbool.h>

struct person
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
	struct person    info;
	struct account*  next;
};

typedef struct account* node;

node createNode();
node addNode(node HEAD, node added);
node deleteNode(node HEAD, int accID);
void printAccounts(node HEAD);


#endif
