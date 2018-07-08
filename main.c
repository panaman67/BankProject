#include <stdio.h>
#include "account.h"
#include "admin.h"
#include "user.h"

void DownloadCustomers(FILE* input, Node acclist);

int main()
{
	Node accounts = CreateNode();
	FILE* accFile;
	
	AddNodeTest(accounts, 44);
	AddNodeTest(accounts, 23);

	accFile = fopen("CustomerData.txt", "r");
	DownloadCustomers(accFile, accounts);
	fclose(accFile);

	printAccounts(accounts);
	
	return 0;
}


/*************************************************************
 Name: DownloadCustomers
 Purpose: Read lines from file and store in LinkedList
 Parameters: FILE* input (pointer to file where data is read)
             Node  acclist (array holding Account type)
 Return value: void
 Side Effects: Modifies accList
*************************************************************/

void DownloadCustomers(FILE* input, Node HEAD)
{
	Node user = CreateNode();
	int adminStatus = 0;
	
	int num = 1;
	while (fscanf(input, "%d %s %s %s %s %s %d %s %f", 
				&adminStatus,
				user->firstName,
				user->lastName,
				user->city,
				user->state,
				user->phoneNumber,
				&user->accID,
				user->password,
				&user->balance))
	{
		user->isAdmin = adminStatus;
		AddNodeTest(HEAD, 1337);
		printf("Added user %d\n", num);
		num++;
	}
	// *accID = atoi(p[i - 1].accountID);
}

/*************************************************************
 Name: UploadCustomers
 Purpose: print out array to a file
 Parameters: FILE* output (pointer to file where array printed)
			 Account p[] (array holding Account type)
			 int numAccounts (number of accounts to write to file)
 Return value: none
 Side Effects: none
*************************************************************/

void UploadCustomers(FILE* output, Node HEAD)
{
	int i = 0;
	while (i < 2)
	{	
		//fprintf(output, "%d %s %s %s %s %s %s %s %.2lf\r\n", p[i].status,
		//		                                     p[i].firstName,
		//						     p[i].lastName,
		//						     p[i].city,
		//						     p[i].state,
		//						     p[i].phoneNumber,
		//						     p[i].accountID,
		//						     p[i].password,
		//						     p[i].balance);
		//i++;
	}
}

