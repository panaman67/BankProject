#include <stdio.h>
#include <string.h>
#include "administrator.h"


Account* createCustomerAccount()
{
	
}

void changePassword(Account* p)
{
	char newPassword[7];
	printf("Enter new password: ");
	scanf("%s", newPassword);
	strcpy(p->password, newPassword);
	printf("Password changed!\n\n");
	printf("%s\n", p->password);
}

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


void changeCustomerInfo(Account p[])
{
	
}






