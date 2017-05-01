#include <stdio.h>
#include <string.h>
#include <ctype.h>
//include header file
#include "administrator.h"

//function for creating account
Account* createCustomerAccount()
{
	
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
void viewCustomerInfo(Account p[])
{
	char ID[6];
	printf("Enter account ID to observe: ");
	scanf("%s", ID);
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (strcmp(p[i].accountID, ID) == 0)
		{
			printf("Status: %d\n", p[i].status);
			printf("First Name: %s\n", p[i].firstName);
			printf("Last Name: %s\n", p[i].lastName);
			printf("City: %s\n", p[i].city);
			printf("State: %s\n", p[i].state);
			printf("Phone Number: %s\n", p[i].phoneNumber);
			printf("Account ID: %s\n", p[i].accountID);
			printf("Password: %s\n", p[i].password);
			printf("Balance: %.2f\n\n", p[i].balance);
			getchar();
			break;
		}
	}
}

//function to select account and modify details other than password
//and balance and ID
void changeCustomerInfo(Account p[])
{
	
}

//function to recieve account ID and delete it from account list
void deleteCustomerAccount(Account data[])
{
	
}

//function to show top 5 accounts based on balance to admin
void showTopFive(Account data[])
{
	
}

//function to show all accounts with last name starting with inputted character
void showAccountsAlpha(Account p[])
{
	char letter;
	printf("Show accounts of last name starting with: ");
	letter = getchar();
	letter = toupper(letter);
	printf("Acc#   FN       LN       Balance\n");
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (p[i].lastName[0] == letter)
		{
			printf("%-6s %-8s %-8s %-.2f\n", p[i].accountID, 
											p[i].firstName, 
											p[i].lastName, 
											p[i].balance);
			break;
		}
	}
}






