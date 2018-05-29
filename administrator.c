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
    return (int)(100.f * ia->balance - 100.f * ib->balance);
	/* float comparison: returns negative if b > a 
	and positive if a > b. We multiplied result by 100.0
	to preserve decimal fraction */
}


/********************************************************************************
 Name: CreateCustomerAccount
 Purpose: create new account
 Parameters: Account data[] (array of accounts)
			 int pos (position in array to be added)
			 int* accNum (pointer to account number to be used for new account)
 Return value: none
 Side Effects: alters data array by addeding an element to the end
********************************************************************************/
void CreateCustomerAccount(Account data[], int pos, int* accNum)
{
	//temp string
	char temp[50];
	data[pos].status = CUSTOMER;
	
	FN:
	printf("Enter new first name: ");
	gets(temp);
	
	if (strlen(temp) > 8 || strlen(temp) <= 0)
	{
		printf("First name MUST be 8 characters or less\n");
		goto FN;
	}
	for (int i = 0; i < strlen(temp); i++)
	{
		if (isspace(temp[i]) || isdigit(temp[i]))
		{
			printf("Can NOT contain whitespace or numbers\n");
			goto FN;
		}
	}
	strcpy(data[pos].firstName, temp);
	
	LN:
	printf("Enter new last name: ");
	gets(temp);
	
	if (strlen(temp) > 8 || strlen(temp) <= 0)
	{
		printf("Last name MUST be 8 characters or less\n");
		goto LN;
	}
	for (int i = 0; i < strlen(temp); i++)
	{
		if (isspace(temp[i]) || isdigit(temp[i]))
		{
			printf("Can NOT contain whitespace or numbers\n");
			goto LN;
		}
	}
	strcpy(data[pos].lastName, temp);
	
	CITY:
	printf("Enter new city name: ");
	gets(temp);
	
	if (strlen(temp) > 10 || strlen(temp) <= 0)
	{
		printf("Last name MUST be 8 characters or less\n");
		goto CITY;
	}
	for (int i = 0; i < strlen(temp); i++)
	{
		if (isspace(temp[i]) || isdigit(temp[i]))
		{
			printf("Can NOT contain whitespace or numbers\n");
			goto CITY;
		}
	}
	strcpy(data[pos].city, temp);
	
	STATE:
	printf("Enter new state (2 character abbrev. ex: TX): ");
	gets(temp);
	
	if (strlen(temp) != 2)
	{
		printf("State MUST be 2 characters\n");
		goto STATE;
	}
	for (int i = 0; i < strlen(temp); i++)
	{
		if (isspace(temp[i]) || isdigit(temp[i]))
		{
			printf("Can NOT contain whitespace or numbers\n");
			goto STATE;
		}
	}
	strcpy(data[pos].state, temp);
	
	PHONE:
	printf("Enter new phone number (XXX-XXXX): ");
	gets(temp);
					
	if (strlen(temp) != 8)
	{
		printf("Phone number MUST be 8 characters\n");
		goto PHONE;
	}
	if (temp[3] != '-')
	{
		printf("MUST be in format XXX-XXXX\n");
		goto PHONE;
	}
	for (int i = 0; i < strlen(temp); i++)
	{
		if (isspace(temp[i]) || isalpha(temp[i]))
		{
			printf("Can NOT contain whitespace or letters\n");
			goto PHONE;
		}
	}
	strcpy(data[pos].phoneNumber, temp);
	
	
	PASS:
	printf("Enter password (6 character max): ");
	gets(temp);
	if (strlen(temp) > 6 || strlen(temp) <= 0)
	{
		printf("Password MUST be between 1 and 6 characters\n");
		goto PASS;
	}
	strcpy(data[pos].password, temp);
	
	
	BALANCE:
	printf("Enter starting balance: ");
	gets(temp);
	if (strlen(temp) <= 0 || strlen(temp) > 10)
	{
		printf("Must enter a number within bounds\n");
		goto BALANCE;
	}
	for (int k = 0; k < strlen(temp); k++)
	{
		if (isalpha(temp[k]) || isspace(temp[k]))
		{
			printf("Balence MUST be a number and no whitespace!\n");
			goto BALANCE;
		}
	}
	//set the accounts balence to the string to double conversion of temp
	data[pos].balance = atof(temp);
	
	//store the value of accNum in the account ID 
	sprintf(data[pos].accountID, "%d", *accNum += 4);
	//call to viewAccountInfo
	viewAccountInfo(&data[pos]);
}

/*************************************************************
 Name: ChangePassword
 Purpose: Change password of currently loged in account (used for admin AND customer)
 Parameters: Account* p (Logged in account)
 Return value: none
 Side Effects: change password field of p
*************************************************************/
void ChangePassword(Account* p)
{
	char temp[50];
	TOP:
	printf("Enter new password: ");
	//gets(temp);
	scanf("%[^\n]", temp);

	if (strlen(temp) > 6 || strlen(temp) <= 0)
	{
		printf("Incorrect password length, max 6 characters!\n");
		goto TOP;
	}
	for (int i = 0; i < strlen(temp); i++)
	{
		if (isspace(temp[i]) || ispunct(temp[i]))
		{
			printf("Password CANNOT contain whitespace or punctuation.\n");
			goto TOP;
		}
	}
	
	strcpy(p->password, temp);
	printf("Password changed to: %s\n\n", p->password);
}

/*************************************************************
 Name: ViewCustomerInfo
 Purpose: Print out each field of a certian account to user
 Parameters: Account data[] (array of accounts)
 Return value: none
 Side Effects: none
*************************************************************/
void ViewCustomerInfo(Account data[], int numAccounts)
{
	char ID[6];
	char temp[20];
	TOP:
	printf("Enter account ID to observe: ");
	gets(temp);
	if (strlen(temp) != 5)
	{
		printf("Incorrect ID length, MUST be 5 numbers.\n");
		goto TOP;
	}
	for (int k = 0; k < strlen(temp); k++)
	{
		if (!isdigit(temp[k]))
		{
			printf("ID MUST be a 5 digit number.\n");
			goto TOP;
		}
	}
	strcpy(ID, temp);
	
	
	int i;
	for (i = 0; i < numAccounts; i++)
	{
		if (strcmp(data[i].accountID, ID) == 0)
		{
			//if status equals 1 then print ADMIN, else print CUSTOMER
			printf("\n\nStatus: %s\n", data[i].status == 1 ? "ADMIN" : "CUSTOMER");
			printf("First Name: %s\n", data[i].firstName);
			printf("Last Name: %s\n", data[i].lastName);
			printf("City: %s\n", data[i].city);
			printf("State: %s\n", data[i].state);
			printf("Phone Number: %s\n", data[i].phoneNumber);
			printf("Account ID: %s\n", data[i].accountID);
			printf("Password: %s\n", data[i].password);
			printf("Balance: %.2f\n\n", data[i].balance);
			break;
		}
	}
	if (i >= numAccounts)
	{
		printf("Account number entered does not exist!\n");
		goto TOP;
	}
}

/*************************************************************
 Name: ChangeCustomerInfo
 Purpose: Change each field of selected account
 Parameters: Account data[] (array of accounts)
 Return value: none
 Side Effects: Changes fields of account chosen in data array
*************************************************************/
void ChangeCustomerInfo(Account data[], int numAccounts)
{
	char temp[50];
	char ID[6];
	int choice;
	
	TOP:
	printf("Enter account ID to change: ");
	gets(temp);
	if (strlen(temp) != 5)
	{
		printf("ID MUST be 5 digits!\n");
		goto TOP;
	}
	for (int k = 0; k < strlen(temp); k++)
	{
		if (!isdigit(temp[k]))
		{
			printf("ID MUST be a 5 digit number.\n");
			goto TOP;
		}
	}
	strcpy(ID, temp);
	
	
	int i;
	for (i = 0; i < numAccounts; i++)
	{
		if (strcmp(data[i].accountID, ID) == 0)
		{
			CHOICE:
			printf("\n1) First name\n");
			printf("2) Last name\n");
			printf("3) City\n");
			printf("4) State\n");
			printf("5) Phone number\n");
			printf("What field do you want to change?: ");
			scanf("%d", &choice);
			while (getchar() != '\n');
			
			switch (choice)
			{
				case 1:
				{
					FIRST:
					printf("Enter new first name: ");
					gets(temp);
					
					if (strlen(temp) > 8)
					{
						printf("First name MUST be 8 characters or less\n");
						goto FIRST;
					}
					for (int i = 0; i < strlen(temp); i++)
					{
						if (isspace(temp[i]) || isdigit(temp[i]))
						{
							printf("Can NOT contain whitespace or numbers\n");
							goto FIRST;
						}
					}
					strcpy(data[i].firstName, temp);
					
					break;
				}
				case 2:
				{
					LAST:
					printf("Enter new last name: ");
					gets(temp);
					
					if (strlen(temp) > 8)
					{
						printf("Last name MUST be 8 characters or less\n");
						goto LAST;
					}
					for (int i = 0; i < strlen(temp); i++)
					{
						if (isspace(temp[i]) || isdigit(temp[i]))
						{
							printf("Can NOT contain whitespace or numbers\n");
							goto LAST;
						}
					}
					strcpy(data[i].lastName, temp);
					
					break;
				}
				case 3:
				{
					CITY:
					printf("Enter new city name: ");
					gets(temp);
					
					if (strlen(temp) > 10)
					{
						printf("Last name MUST be 8 characters or less\n");
						goto CITY;
					}
					for (int i = 0; i < strlen(temp); i++)
					{
						if (isspace(temp[i]) || isdigit(temp[i]))
						{
							printf("Can NOT contain whitespace or numbers\n");
							goto CITY;
						}
					}
					strcpy(data[i].city, temp);
					
					break;
				}
				case 4:
				{
					STATE:
					printf("Enter new state (2 character abbrev. ex: TX): ");
					gets(temp);
					
					if (strlen(temp) != 2)
					{
						printf("State MUST be 2 characters\n");
						goto STATE;
					}
					for (int i = 0; i < strlen(temp); i++)
					{
						if (isspace(temp[i]) || isdigit(temp[i]))
						{
							printf("Can NOT contain whitespace or numbers\n");
							goto STATE;
						}
					}
					strcpy(data[i].state, temp);
					break;
				}
				case 5:
				{
					PN:
					printf("Enter new phone number (XXX-XXXX): ");
					gets(temp);
					
					if (strlen(temp) != 8)
					{
						printf("Phone number MUST be 8 characters\n");
						goto PN;
					}
					if (temp[3] != '-')
					{
						printf("MUST be in format XXX-XXXX\n");
						goto PN;
					}
					for (int i = 0; i < strlen(temp); i++)
					{
						if (isspace(temp[i]) || isalpha(temp[i]))
						{
							printf("Can NOT contain whitespace or letters\n");
							goto PN;
						}
					}
					strcpy(data[i].phoneNumber, temp);
					break;
				}
				default:
				{
					printf("\nNot valid choice!\n\n");
					goto CHOICE;
				}
			}
			break;
		}
	}
	
	if (i >= numAccounts)
	{
		printf("No account found!\n");
		goto TOP;
	}
}


/*************************************************************
 Name: DeleteCustomerAccount
 Purpose: Deletes record of chosen account
 Parameters: Account data[] (account array)
			 int numAccounts
 Return value: none
 Side Effects: Changes data array
*************************************************************/
void DeleteCustomerAccount(Account data[], int numAccounts)
{
	/*
	char ID[6];
	printf("Enter account ID to delete: ");
	scanf("%5s", ID);
	fflush();

	for (int i = 0; i < numAccounts; i++)
	{
		if (strcmp(data[i].accountID, ID) == 0)
		{
			strcpy(data[i].accountID, "\0");
			data[i].balance = 0;
			break;
		}
	}
	*/
	printf("\nDeleteCustomerAccount function corrupts data file. Could not safetly implement\n\n");
}

/*************************************************************
 Name: ShowTopFive
 Purpose: Prints out the top 5 accounts by balance
 Parameters: Account data[] (account array)
 Return value: none
 Side Effects: none
*************************************************************/
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

/*************************************************************
 Name: ShowAccountsAlpha
 Purpose: Show all accounts with last name starting with letter chosen by user
 Parameters: Account data[] (account array)
 Return value: none
 Side Effects: none
*************************************************************/
void ShowAccountsAlpha(Account data[], int numAccounts)
{
	char letter;
	printf("Show accounts of last name starting with: ");
	letter = getchar();
	letter = toupper(letter);
	printf("ACC#          FName           LName                  Balance\n");
	printf("------------------------------------------------------------\n");
	for (int i = 0; i < numAccounts; i++)
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






