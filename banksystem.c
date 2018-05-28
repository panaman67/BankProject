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
void DownloadCustomers(FILE* input, Account p[], int* numAccounts, int* accID);
void UploadCustomers(FILE* output, Account p[], int numAccounts);

/*************************************************************
 Name: main
 Purpose: Create variables, call functons, and display output
 Parameters: none
 Return value: int (program success)
 Side Effects: none
*************************************************************/
int main(int argc, char* argv[])
{
	//strings for ID and password
	char ID[MAX_LENGTH_LOGIN + 1], password[MAX_LENGTH_LOGIN + 1];
	//file pointer to input data
	FILE* data;
	int numAccounts = 0;
	char* fileName = argv[1];
	//string for holding input temporarily
	char temp[50];
	//integer for account number for new accounts
	int IDnumberForNewAccount;
	//Account pointer for logged in account
	Account* accountCurr;
	//Account array
	Account accounts[MAX_CUSTOMERS];
	
	//print welcome screen
	printf("\nWelcome to Online Banking / ATM System\n");
	printf(  "======================================\n\n");
	
	
	LOGIN_ID:
	//prompt user for ID and password
	printf("Enter your Customer/Admin ID: ");
	gets(temp);
	
	if (strlen(temp) != 5)
	{
		printf("ID length incorrect, must be 5 characters.\n");
		goto LOGIN_ID;
	}
	//copy string into ID
	strcpy(ID, temp);
	
	LOGIN_PASS:
	printf("Enter your Customer/Admin Password: ");
	gets(temp);
	
	if (strlen(temp) > 6 && strcmp(temp, "admin") != 0)
	{
		printf("Password length incorrect, must be 6 characters.\n");
		goto LOGIN_PASS;
	}
	strcpy(password, temp);
	
	//open file for reading
	data = fopen(fileName, "r");
	DownloadCustomers(data, accounts, &numAccounts, &IDnumberForNewAccount);
	//close file
	fclose(data);
	
	
	
	//search for account matching ID and password
	int i;
	for (i = 0; i < numAccounts; i++)
	{
		if (strcmp(accounts[i].accountID, ID) == 0 && strcmp(accounts[i].password, password) == 0)
		{
			//set accountCurr pointer to point at account at i in accounts array
			accountCurr = &accounts[i];
			break;
		}
	}
	//if looped through and no account found
	if (i >= numAccounts)
	{
		printf("No account found with this login info!\n");
		goto LOGIN_ID;
	}
	

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
			//clears input buffer
			while(getchar() != '\n');
			
			data = fopen(fileName, "r");
			DownloadCustomers(data, accounts, &numAccounts, &IDnumberForNewAccount);
			fclose(data);
			//do action based on choice
			switch (choice)
			{
				case 1:
				{
					CreateCustomerAccount(accounts, numAccounts, &IDnumberForNewAccount);
					numAccounts++;
					break;
				}
				case 2:
				{
					ChangePassword(accountCurr);
					break;
				}
				case 3:
				{
					ViewCustomerInfo(accounts, numAccounts);
					break;
				}
				case 4:
				{
					ChangeCustomerInfo(accounts, numAccounts);
					break;
				}
				case 5:
				{
					DeleteCustomerAccount(accounts, numAccounts);
					break;
				}
				case 6:
				{
					ShowTopFive(accounts);
					break;
				}
				case 7:
				{
					ShowAccountsAlpha(accounts, numAccounts);
					break;
				}
				case 8:
				{
					printf("\n\nSession terminated. Have a nice day!\n\n");
					exit(0);
				}
				default:
				{
					printf("Not vlaid choice!\n");
				}
			}
			//open file with write privilages
			data = fopen(fileName, "w");
			UploadCustomers(data, accounts, numAccounts);
			fclose(data);
		}
	}

	
	//  CUSTOMER
	if (accountCurr->status == CUSTOMER)
	{
		while (1)
		{
			data = fopen(fileName, "r");
			DownloadCustomers(data, accounts, &numAccounts, &IDnumberForNewAccount);
			fclose(data);
			
			
			DisplayMenu(CUSTOMER);
			printf("Enter an option: ");
			scanf("%d", &choice);
			while (getchar() != '\n');
			

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
					printf("\n\nSession terminated. Have a nice day!\n\n");
					exit(0);
				}
				default:
				{
					printf("Not valid choice!\n");
				}
			}
			//open file with write privilages
			data = fopen(fileName, "w");
			UploadCustomers(data, accounts, numAccounts);
			fclose(data);
		}
	}
	

	//close data file
	return 0;
}

/*************************************************************
 Name: DownloadCustomers
 Purpose: read lines from file and store in array
 Parameters: FILE* input (pointer to file where data is read)
			 Account p[] (array holding Account type)
			 int* numAccounts (pointer to number of accounts)
			 int* accID (starting account number to store when new account is added)
 Return value: none
 Side Effects: modifies p array
*************************************************************/
void DownloadCustomers(FILE* input, Account p[], int* numAccounts, int* accID)
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
	
	int k;
	for (k = 0; k < MAX_CUSTOMERS; k++)
	{
		if (p[k].status != CUSTOMER && p[k].status != ADMIN)
		{
			break;
		}
	}
	*numAccounts = k;
	
	
	*accID = atoi(p[k - 1].accountID);
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

/*************************************************************
 Name: DisplayMenu
 Purpose: print out menu depending on account type
 Parameters: int mode (either 1 for admin or 2 for customer)
 Return value: none
 Side Effects: none
*************************************************************/
void DisplayMenu(int mode)
{
	if (mode == ADMIN)
	{
		printf("\n--------------------\n");
		printf("Administrator Menu\n");
		printf("----------------------\n");
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
