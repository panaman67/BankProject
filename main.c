#include <stdio.h>
#include <string.h>
#include "account.h"
#include "admin.h"
#include "user.h"

Node DownloadCustomers(FILE* input);
Node LoadAccounts(FILE* input);
void StoreAccoubnts(FILE* output);

int main()
{
	//Node accounts = CreateNode();
	Node accList = NULL;
	FILE* accFile;
	
	//AddNodeTest(accounts, 44);
	//AddNodeTest(accounts, 23);

	accFile = fopen("CustomerData.txt", "r");
	//accList = DownloadCustomers(accFile);
	accList = LoadAccounts(accFile);
	fclose(accFile);

	//printf("%ld\n", sizeof(List));

	PrintAccounts(accList);
	
	return 0;
}

/*************************************************************
 Name: LoadCustomers
 Purpose: Read lines from file and store in LinkedList
 Parameters: FILE* input (pointer to file where data is read)
 Return value: Node (Head of list)
 Side Effects: Modifies HEAD
*************************************************************/
Node LoadAccounts(FILE* input)
{
	Node HEAD = CreateNode();
	Node temp = CreateNode();
	List user;
	//char buffer[30]; 

	// do
	// {
	// 	fscanf(input, "%s", buffer);
	// 	printf("%s", buffer);
	// } while (getchar() != '\n');
	//while (fscanf(input, "%s", buffer) > 0)
	//{
	//	printf("%s\n", buffer);
	//}

	while (fscanf(input, "%s %s %s %s %s %d %s %lf",	user.firstName,
														user.lastName,
														user.city,
														user.state,
														user.phoneNumber,
														&user.accID,
														user.password,
														&user.balance) > 0)
	{
		*temp = user;
		AddNodeTest(HEAD, 1337);
		printf("%lf\n", user.balance);
	}

	return HEAD;
}

/*************************************************************
 Name: UploadCustomers
 Purpose: Print out List to a file
 Parameters: FILE* output (pointer to file where array printed)
			 Node HEAD (Pointer to head of list)
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
		i++;
	}
}


