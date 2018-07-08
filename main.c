#include <stdio.h>
#include "admin.h"
#include "account.h"
#include "user.h"

int main()
{
	Node accounts = CreateNode();
	
	AddNode(accounts, 44);
	printAccounts(accounts);

	return 0;
}


/*************************************************************
 Name: DownloadCustomers
 Purpose: read lines from file and store in LinkedList
 Parameters: FILE* input (pointer to file where data is read)
			 node acclist (array holding Account type)
			 int* numAccounts (pointer to number of accounts)
			 int* accID (starting account number to store when new account is added)
 Return value: none
 Side Effects: modifies p array
*************************************************************/
/*
void DownloadCustomers(FILE* input, Node acclist, int* accID)
{
	Node temp = acclist;
	Node user = createNode();
	int adminStatus = 0;

	while (fscanf(input, "%d %s %s %s %s %s %d %s %f", 
				&adminStatus,
				user->info.firstName,
				user->info.lastName,
				user->info.city,
				user->info.state,
				user->info.phoneNumber,
				&user->accID,
				user->password,
				&user->balance) != EOF)
	{
		user->isAdmin = adminStatus;
		AddNode(acclist, &user);

	}
	// *accID = atoi(p[i - 1].accountID);
}
*/
/*************************************************************
 Name: UploadCustomers
 Purpose: print out array to a file
 Parameters: FILE* output (pointer to file where array printed)
			 Account p[] (array holding Account type)
			 int numAccounts (number of accounts to write to file)
 Return value: none
 Side Effects: none
*************************************************************/
/*
void UploadCustomers(FILE* output, Account p[], int numAccounts)
{
	int i = 0;
	while (i < numAccounts)
	{	
		fprintf(output, "%d %s %s %s %s %s %s %s %.2lf\r\n", p[i].status,
				                                     p[i].firstName,
								     p[i].lastName,
								     p[i].city,
								     p[i].state,
								     p[i].phoneNumber,
								     p[i].accountID,
								     p[i].password,
								     p[i].balance);
		i++;
	}
}
*/
