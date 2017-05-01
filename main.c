#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "administrator.h"
#include "customer.h"

//function prototypes
void DisplayMenu(int mode);
void DownloadCustomers(FILE* input, Account p[]);
void UploadCustomers(FILE* input, Account p[]);


int main(int argc, char* argv[])
{
	//strings for ID and password
	char ID[MAX_LENGTH_LOGIN + 1], password[MAX_LENGTH_LOGIN + 1];
	//file pointer to input data
	FILE* data;
	int freePosition = 10;
	
	//Account pointer for logged in account
	Account* accountCurr;
	

	
	//store data from file in data
	data = fopen("CustomerData.txt", "r+");
	//account array
	Account accounts[MAX_CUSTOMERS];
	
	//print welcome screen
	printf("\nWelcome to Online Banking/ATM System\n");
	printf("====================================\n\n");
	
	//prompt user for ID and password
	printf("Enter your Customer/Admin ID: ");
	scanf("%5s", ID);
	ID[MAX_LENGTH_LOGIN] = '\0';
	
	printf("Enter your Customer/Admin Password: ");
	scanf("%5s", password);
	password[MAX_LENGTH_LOGIN] = '\0';
	
	
	//call DownloadCustomers
	DownloadCustomers(data, accounts);
	
	
	
	//search for account matching ID and password
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if (strcmp(accounts[i].accountID, ID) == 0 && strcmp(accounts[i].password, password) == 0)
		{
			accountCurr = &accounts[i];
			break;
		}
	}
	
	//printf("%d\n\n", accountCurr -> status);
	
	//int variable for choice
	int choice;
	//if admin
	if (accountCurr->status == ADMIN)
	{
		while(1)
		{
			//display menu
			DisplayMenu(ADMIN);

			printf("Enter an option: ");
			scanf("%d", &choice);
			getchar();
			
			//do action based on choice
			switch (choice)
			{
				case 1:
				{
					createCustomerAccount(accounts, freePosition);
					freePosition++;
					break;
				}
				case 2:
				{
					changePassword(accountCurr);
					break;
				}
				case 3:
				{
					viewCustomerInfo(accounts);
					break;
				}
				case 4:
				{
					changeCustomerInfo(accounts);
					break;
				}
				case 5:
				{
					deleteCustomerAccount(accounts);
					break;
				}
				case 6:
				{
					showTopFive(accounts);
					break;
				}
				case 7:
				{
					showAccountsAlpha(accounts);
					break;
				}
			}
			
		}
	}

	
	//  CUSTOMER
	if (accountCurr->status == CUSTOMER)
	{
		while (1)
		{
			DisplayMenu(CUSTOMER);
			printf("Enter an option: ");
			scanf("%d", &choice);
			getchar();
			

			switch (choice)
			{
				case 1:
				{
					changePassword(accountCurr);
					break;
				}
				case 2:
				{
					viewAccountInfo(accountCurr);
					break;
				}
				case 3:
				{
					ViewBalance(accountCurr);
					break;
				}
				case 4:
				{
					depositMoney(accountCurr);
					break;
				}
				case 5:
				{
					transferMoney(accountCurr, accounts);
					break;
				}
				case 6:
				{
					withdrawMoney(accountCurr);
				}
			}
		}
	}
	

	//close data file
	fclose(data);
	return 0;
}

//function to load accounts from text file
void DownloadCustomers(FILE* input, Account p[])
{
	int i = 0;
	while (i < MAX_CUSTOMERS)
	{
		fscanf(input, "%d %s %s %s %s %s %s %s %lf", &p[i].status,
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

//function to put accounts bact to text file
void UploadCustomers(FILE* input, Account p[])
{
	
}

//function to display correct menu based on who is logged in
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
		printf("1)  Change Password\n");
		printf("2)  View Customer information\n");
		printf("3)  View Balance\n");
		printf("4)  Make a Deposit\n");
		printf("5)  Transfer Money\n");
		printf("6)  Withdraw Money\n");
		printf("7)  Exit\n");
	}
}
