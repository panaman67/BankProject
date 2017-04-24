#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "administrator.h"
#include "customer.h"


void DisplayMenu(int mode);
void LoadCustomers(FILE* input, Account p[]);


int main(int argc, char* argv[])
{
	char ID[MAX_LENGTH_LOGIN + 1], password[MAX_LENGTH_LOGIN + 1];
	FILE* data;
	Account* accountCurr;
	
	data = fopen("CustomerData.txt", "r+");
	
	Account accounts[MAX_CUSTOMERS];
	
	
	
	
	printf("\nWelcome to Online Banking/ATM System\n");
	printf("====================================\n\n");
	
	printf("Enter your Customer/Admin ID: ");
	scanf("%5s", ID);
	ID[MAX_LENGTH_LOGIN] = '\0';
	
	printf("Enter your Customer/Admin Password: ");
	scanf("%5s", password);
	password[MAX_LENGTH_LOGIN] = '\0';
	
	LoadCustomers(data, accounts);
	
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (strcmp(accounts[i].accountID, ID) == 0)
		{
			accountCurr = &accounts[i];
			break;
		}
	}
	//printf("%s\n\n\n", accountCurr->firstName);
	
	//DisplayMenu(accountCurr->status);
	int choice;
	if (accountCurr->status == ADMIN)
	{
		while(1)
		{
			DisplayMenu(ADMIN);

			printf("Enter an option: ");
			scanf("%d", &choice);
			getchar();
			
			//printf("%d\n\n\n\n", choice);
			switch (choice)
			{
				case 2:
				{
					changePassword(accountCurr);
				}
				case 3:
				{
					viewCustomerInfo(accounts);
				}
				case 4:
				{
					changeCustomerInfo(accounts);
				}
			}
			
		}
	}
	
	if (accountCurr->status == CUSTOMER)
	{
		while (1)
		{
			DisplayMenu(CUSTOMER);
			printf("Enter an option: ");
			scanf("%d", &choice);
			getchar();
			
			//printf("%d\n\n\n\n", choice);
			switch (choice)
			{
				case 1:
				{
					ViewBalance(accountCurr);
				}
			}
		}
	}
	fclose(data);
	return 0;
}

void LoadCustomers(FILE* input, Account p[])
{
	int i = 0;
	while (i < MAX_CUSTOMERS)
	{
		fscanf(input, "%d %s %s %s %s %s %s %s %f", &p[i].status,
												     p[i].firstName,
												     p[i].lastName,
												     p[i].city,
												     p[i].state,
												     p[i].phoneNumber,
												     p[i].accountID,
												     p[i].password,
												    &p[i].balance);
		i++;
	}
	//printf("%s\n\n\n", p[0].balance);
}


void DisplayMenu(int mode)
{
	if (mode == ADMIN)
	{
		printf("\n--------------------\n");
		printf("Administrator Menu\n");
		printf("--------------------\n");
		printf("1)  Create Customer account\n");
		printf("2)  Change Password\n");
		printf("3)  View Customer Info\n");
		printf("4)  Change Customer Info\n");
		printf("5)  Delete Customer account\n");
		printf("6)  Show Top 5 accounts\n");
		printf("7)  Show customer accounts alphabetically\n");
		printf("8)  Exit\n");
	}
	else if (mode == CUSTOMER)
	{
		printf("--------------------\n");
		printf("Customer Menu\n");
		printf("--------------------\n");
		printf("a)  Change Password\n");
		printf("b)  View Customer information\n");
		printf("c)  View Balance\n");
		printf("d)  Make a Deposit\n");
		printf("e)  Transfer Money\n");
		printf("f)  Withdraw Money\n");
		printf("g)  Exit\n");
	}
}
