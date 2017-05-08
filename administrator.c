/*
Names:   Nicholas Paladino
	     James Sigler
Section: 502
Purpose: To define functions and give functionality to admin type accounts
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//include header file
#include "administrator.h"
#include "customer.h"

/*************************************************************
 Name: StructCmp
 Purpose: compares balance of two Accounts
 Parameters: const void *a (balence a)
			 const void *b (balance b)
 Return value: int (difference of values)
 Side Effects: none
*************************************************************/
int StructCmp(const void *a, const void *b) 
{ 
    Account* ia = (Account*)a;
    Account* ib = (Account*)b;
    return (int)(100.f*ia->balance - 100.f*ib->balance);
	/* float comparison: returns negative if b > a 
	and positive if a > b. We multiplied result by 100.0
	to preserve decimal fraction */
}


/*************************************************************
 Name: CreateCustomerAccount
 Purpose: create new account
 Parameters: Account data[] (array of accounts)
			 int pos (position in array to be added)
 Return value: none
 Side Effects: alters data array
*************************************************************/
void CreateCustomerAccount(Account data[], int pos, int* accNum)
{
	char temp[50];
	data[pos].status = CUSTOMER;
	
	FN:
	printf("Enter first name: ");
	scanf("%s", temp);
	if (strlen(temp) > 8)
	{
		printf("First name too long, max of 8 characters.\n");
		goto FN;
	}
	strcpy(data[pos].firstName, temp);
	
	LN:
	printf("Enter last name: ");
	scanf("%s", temp);
	if (strlen(temp) > 8)
	{
		printf("Last name too long, max of 8 characters.\n");
		goto LN;
	}
	strcpy(data[pos].lastName, temp);
	
	CITY:
	printf("Enter city: ");
	scanf("%s", temp);
	if (strlen(temp) > 10)
	{
		printf("City name too long, max of 10 characters.\n");
		goto CITY;
	}
	strcpy(data[pos].city, temp);
	
	STATE:
	printf("Enter state (2 character abbrev.): ");
	scanf("%s", temp);
	if (strlen(temp) != 2)
	{
		printf("State invalid, MUST be 2 characters.\n");
		goto STATE;
	}
	strcpy(data[pos].state, temp);
	
	PHONE:
	printf("Enter phone number (XXX-XXXX): ");
	scanf("%s", temp);
	if (strlen(temp) != 8)
	{
		printf("Phone number MUST be in format XXX-XXXX.\n");
		goto PHONE;
	}
	strcpy(data[pos].phoneNumber, temp);
	
	PASS:
	printf("Enter password (6 character max): ");
	scanf("%s", temp);
	if (strlen(temp) > 6)
	{
		printf("Phone number MUST be in format XXX-XXXX.\n");
		goto PHONE;
	}
	strcpy(data[pos].password, temp);
	
	
	BALANCE:
	printf("Enter starting balance: ");
	scanf("%s", temp);
	for (int k = 0; k < strlen(temp); k++)
	{
		if (isalpha(temp[k]))
		{
			printf("Balence MUST be a number!\n");
			goto BALANCE;
		}
		else if (isspace(temp[k]))
		{
			printf("Cant include whitespace!\n");
			goto BALANCE;
		}
	}
	data[pos].balance = atoi(temp);
	
	sprintf(data[pos].accountID, "%d", *accNum += 4);
	
	viewAccountInfo(&data[pos]);
}

//change password function for currently logged in account
void ChangePassword(Account* p)
{
	char newPassword[7];
	printf("Enter new password: ");
	scanf("%s", newPassword);
	strcpy(p->password, newPassword);
	printf("Password changed!\n\n");
	printf("%s\n", p->password);
}

//function for viewing selected account
void ViewCustomerInfo(Account data[])
{
	char ID[6];
	printf("Enter account ID to observe: ");
	scanf("%s", ID);
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (strcmp(data[i].accountID, ID) == 0)
		{
			printf("\n\nStatus: %s\n", data[i].status == 1 ? "ADMIN" : "CUSTOMER");
			printf("First Name: %s\n", data[i].firstName);
			printf("Last Name: %s\n", data[i].lastName);
			printf("City: %s\n", data[i].city);
			printf("State: %s\n", data[i].state);
			printf("Phone Number: %s\n", data[i].phoneNumber);
			printf("Account ID: %s\n", data[i].accountID);
			printf("Password: %s\n", data[i].password);
			printf("Balance: %.2f\n\n", data[i].balance);
			getchar();
			break;
		}
	}
}

//function to select account and modify details other than password
//and balance and ID
void ChangeCustomerInfo(Account data[])
{
	char ID[6];
	int choice;
	printf("Enter account ID to change: ");
	scanf("%5s", ID);
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (strcmp(data[i].accountID, ID) == 0)
		{
			printf("1) First name\n");
			printf("2) Last name\n");
			printf("3) City\n");
			printf("4) State\n");
			printf("5) Phone number\n");
			printf("What field do you want to change?: ");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:
				{
					printf("Enter new first name: ");
					scanf("%s", data[i].firstName);
					break;
				}
				case 2:
				{
					printf("Enter new last name: ");
					scanf("%s", data[i].lastName);
					break;
				}
				case 3:
				{
					printf("Enter new city: ");
					scanf("%s", data[i].city);
					break;
				}
				case 4:
				{
					printf("Enter new state: ");
					scanf("%s", data[i].state);
					break;
				}
				case 5:
				{
					printf("Enter new phone number (XXX-XXXX): ");
					scanf("%s", data[i].phoneNumber);
					break;
				}
			}
		}
	}
}


//function to recieve account ID and delete it from account list
void DeleteCustomerAccount(Account data[], int numAccounts)
{
	
	char ID[6];
	printf("Enter account ID to delete: ");
	scanf("%5s", ID);
	
	for (int i = 0; i < numAccounts; i++)
	{
		if (strcmp(data[i].accountID, ID) == 0)
		{
			strcpy(data[i].accountID, "\0");
			data[i].balance = 0;
			break;
		}
	}
}

//function to show top 5 accounts based on balance to admin
void ShowTopFive(Account data[])
{
	qsort(data, MAX_CUSTOMERS, sizeof(Account), StructCmp);
	printf("ACC#          FName           LName                  Balance\n");
	printf("------------------------------------------------------------\n");
	for (int i = MAX_CUSTOMERS - 1; i > MAX_CUSTOMERS - 6; i--)
	{
		printf("%-13s %-15s %-15s %14.2f\n", data[i].accountID, 
											 data[i].firstName, 
											 data[i].lastName, 
											 data[i].balance);
	}
}

//function to show all accounts with last name starting with inputted character
void ShowAccountsAlpha(Account data[])
{
	char letter;
	printf("Show accounts of last name starting with: ");
	letter = getchar();
	letter = toupper(letter);
	printf("ACC#          FName           LName                  Balance\n");
	printf("------------------------------------------------------------\n");
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (data[i].lastName[0] == letter)
		{
			printf("%-13s %-15s %-15s %14.2f\n", data[i].accountID, 
												 data[i].firstName, 
												 data[i].lastName, 
												 data[i].balance);
		}
	}
}






