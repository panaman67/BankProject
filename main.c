/*
Names:   Nicholas Paladino
	     James Sigler
Section: 502
Purpose: To simulate a banking system
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "administrator.h"
#include "customer.h"

//function prototypes
void DisplayMenu(int mode);
void DownloadCustomers(FILE* input, Account p[], int numAccounts);
void UploadCustomers(FILE* output, Account p[], int numAccounts);


int main(int argc, char* argv[])
{
	//strings for ID and password
	char ID[MAX_LENGTH_LOGIN + 1], password[MAX_LENGTH_LOGIN + 1];
	//file pointer to input data
	FILE* data;
	int freePosition = 11;
	char* fileName = argv[1];
	//integer for account number for new accounts
	int numberForNewAccount = 13598;
	//Account pointer for logged in account
	Account* accountCurr;
	//Account array
	Account accounts[MAX_CUSTOMERS];
	
	//print welcome screen
	printf("\nWelcome to Online Banking/ATM System\n");
	printf("====================================\n\n");
	
	char temp[100];
	
	LOGIN_ID:
	//prompt user for ID and password
	printf("Enter your Customer/Admin ID: ");
	scanf("%s", temp);
	//ID[MAX_LENGTH_LOGIN] = '\0';
	
	if (strlen(temp) != 5)
	{
		printf("ID length incorrect, must be 5 characters.\n");
		goto LOGIN_ID;
	}
	strcpy(ID, temp);
	//temp[0] = '\0';
	
	LOGIN_PASS:
	printf("Enter your Customer/Admin Password: ");
	scanf("%s", temp);
	//password[MAX_LENGTH_LOGIN] = '\0';
	
	if (strlen(temp) != 6 && strcmp(temp, "admin") != 0)
	{
		printf("Password length incorrect, must be 6 characters.\n");
		goto LOGIN_PASS;
	}
	strcpy(password, temp);
	
	
	data = fopen(fileName, "r");
	DownloadCustomers(data, accounts, freePosition);
	fclose(data);
	
	//search for account matching ID and password
	int i;
	for (i = 0; i < freePosition; i++)
	{
		if (strcmp(accounts[i].accountID, ID) == 0 && strcmp(accounts[i].password, password) == 0)
		{
			accountCurr = &accounts[i];
			break;
		}
	}
	if (i >= freePosition)
	{
		printf("No account found with this login info!\n");
		goto LOGIN_ID;
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
			while(getchar() != '\n');
			
			data = fopen(fileName, "r");
			DownloadCustomers(data, accounts, freePosition);
			fclose(data);
			//do action based on choice
			switch (choice)
			{
				case 1:
				{
					CreateCustomerAccount(accounts, freePosition, &numberForNewAccount);
					freePosition++;
					break;
				}
				case 2:
				{
					ChangePassword(accountCurr);
					break;
				}
				case 3:
				{
					ViewCustomerInfo(accounts);
					break;
				}
				case 4:
				{
					ChangeCustomerInfo(accounts);
					break;
				}
				case 5:
				{
					DeleteCustomerAccount(accounts);
					break;
				}
				case 6:
				{
					ShowTopFive(accounts);
					break;
				}
				case 7:
				{
					ShowAccountsAlpha(accounts);
					break;
				}
			}
			data = fopen(fileName, "w");
			UploadCustomers(data, accounts, freePosition);
			fclose(data);
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
					ChangePassword(accountCurr);
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
					break;
				}
				case 7:
				{
					
				}
			}
		}
	}
	

	//close data file
	return 0;
}

//function to load accounts from text file
void DownloadCustomers(FILE* input, Account p[], int numAccounts)
{
	int i = 0;
	while (i < numAccounts)
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
	fclose(input);
}

//function to put accounts bact to text file
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
