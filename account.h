#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct
{
	char*     firstName;
	char*     lastName;
	char*     city;
	char*     state;
} personalInfo;




typedef struct account account;
typedef struct account
{
	short     isAdmin;
	float     balance;
	account*  next;
} Accounts; // Bikeshedd name






#endif
