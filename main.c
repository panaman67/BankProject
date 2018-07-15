#include <stdio.h>
#include <string.h>
#include "account.h"
#include "admin.h"
#include "user.h"

Node LoadAccounts(FILE* input);
void StoreAccounts(FILE* output, Node HEAD);

int main()
{
	FILE* accFile;
	Node accList;

	accFile = fopen("CustomerData.txt", "r");
	accList = LoadAccounts(accFile);
	fclose(accFile);

	PrintAccounts(accList);
	
	return 0;
}

/*************************************************************
 Name: LoadAccounts
 Purpose: Read lines from file and store in LinkedList
 Parameters: FILE* input (pointer to file where data is read)
 Return value: Node (Head of list)
 Side Effects: Modifies HEAD
*************************************************************/
Node LoadAccounts(FILE* input)
{
	Node HEAD = CreateNode();
	List user;

	while (fscanf(input, "%s %s %s %s %s %d %s %lf",	user.firstName,
														user.lastName,
														user.city,
														user.state,
														user.phoneNumber,
														&user.accID,
														user.password,
														&user.balance) == 8)
		AddNode(HEAD, user);
	return HEAD;
}

/*************************************************************
 Name: StoreAccounts
 Purpose: Store accounts to file
 Parameters: FILE* output (pointer to file where array printed)
			 Node HEAD (Pointer to head of list)
 Return value: none
 Side Effects: Changes content of output file
*************************************************************/
void StoreAccounts(FILE* output, Node HEAD)
{
	int i = 0;
	while (i < 2)
	{
		i++;
	}
}
