#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//include header file
#include "administrator.h"

int struct_cmp_by_balance(const void *a, const void *b) 
{ 
    Account* ia = (Account*)a;
    Account* ib = (Account*)b;
    return (int)(100.f*ia->balance - 100.f*ib->balance);
	/* float comparison: returns negative if b > a 
	and positive if a > b. We multiplied result by 100.0
	to preserve decimal fraction */ 
 
} 



//function for creating account
void createCustomerAccount(Account data[], int pos)
{
	data[pos].status = 1;
	printf("Enter first name: ");
	scanf("%s", data[pos].firstName);
	printf("Enter last name: ");
	scanf("%s", data[pos].lastName);
	printf("Enter city: ");
	scanf("%s", data[pos].city);
	printf("Enter state: ");
	scanf("%s", data[pos].state);
	printf("Enter phone number (XXX-XXXX): ");
	scanf("%s", data[pos].phoneNumber);
	printf("Enter account ID: ");
	scanf("%s", data[pos].accountID);
	printf("Enter Password: ");
	scanf("%s", data[pos].password);
	printf("Enter starting balance: ");
	scanf("%f", &data[pos].balance);
}

//change password function for currently logged in account
void changePassword(Account* p)
{
	char newPassword[7];
	printf("Enter new password: ");
	scanf("%s", newPassword);
	strcpy(p->password, newPassword);
	printf("Password changed!\n\n");
	printf("%s\n", p->password);
}

//function for viewing selected account
void viewCustomerInfo(Account data[])
{
	char ID[6];
	printf("Enter account ID to observe: ");
	scanf("%s", ID);
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (strcmp(data[i].accountID, ID) == 0)
		{
			printf("\nStatus: %d\n", data[i].status);
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
void changeCustomerInfo(Account data[])
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
void deleteCustomerAccount(Account data[])
{
	
	char ID[6];
	printf("Enter account ID to delete: ");
	scanf("%5s", ID);
	
	for (int i = 0; i < MAX_CUSTOMERS; i++)
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
void showTopFive(Account data[])
{
	qsort(data, MAX_CUSTOMERS, sizeof(Account), struct_cmp_by_balance);
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
void showAccountsAlpha(Account data[])
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






