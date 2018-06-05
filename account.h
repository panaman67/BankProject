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

node insert(int idx, node added);
node add(node HEAD, node added);
void deleteNode(int accID);


#endif
