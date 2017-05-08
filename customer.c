/*
Name: Nicholas Paladino 
	  James Sigler
	  
Section: 502
Purpose: To create functions and give the their functionality 
		 when accessing the user account type in main meniu

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//include header files

#include "customer.h"
#include "administrator.h"

#define MAX_TRANSACTION 5000

/******************************************************************************************
* 	Name:	ViewBalance
*	Purpose:	To display the balance of the account that is currently logged in.
*	Parameters:		Account* accountCurr - pointer to the current 
*					account structure information
*				
*	Side effects: None
*******************************************************************************************/
void ViewBalance(Account* accountCurr)
{
	printf("Your balance is: %.2f\n", accountCurr -> balance);
}


/******************************************************************************************
* 	Name:	depositMoney
*	Purpose:	To take a user defined amount and add it to their account's balance.
*	Parameters:		Account* accountCurr - pointer to the current 
*					account structure information
*				
*	Side effects: Adds to the balance of the current users account
*******************************************************************************************/
void depositMoney(Account* accountCurr)
{
	double amountToDeposit;
	
	inputDeposit:
	printf("Enter amount to deposit(maximum of $5000): ");
	scanf("%lf", &amountToDeposit);
	if((amountToDeposit <= 0) || (amountToDeposit > MAX_TRANSACTION))
	{
		printf("Invalid deposit amount\n");
		goto inputDeposit;
	}
	accountCurr -> balance += amountToDeposit;
	printf("New balance: %.2lf\n\n", accountCurr->balance);
}


/******************************************************************************************
* 	Name:	transferMoney
*	Purpose:	To take an amount of money from the current users account and transfer
*				the amount to another specified user's account.
*	Parameters:		Account* accountCurr - pointer to the current 
*					account structure information
*					Account* p[] - pointer to another users account to transfer money to.
*				
*	Side effects: Subtracts the amount to transfer from the current users account and adds
*				  that amount to the another user specified by the current user.
*******************************************************************************************/
void transferMoney(Account* accountCurr, Account p[])
{
	double amountToTransfer;
	char accountID[6];
	
	inputID:
	printf("Enter account number to transfer to: ");
	scanf("%s", accountID);
	for(int n = 0; n < strlen(accountID); n++)
	{
		if((strlen(accountID) > 5) || (isdigit(accountID[n]) == false))
		{
			printf("Invalid account ID\n");
			goto inputID;
		}
	}
	inputTransfer:
	printf("Enter amount to transfer to %s :", accountID);
	scanf("%lf", &amountToTransfer);
	
	if(amountToTransfer <= 0)
	{
		printf("Invalid amount:\n");
		goto inputTransfer;
	}
	
	if(amountToTransfer > accountCurr -> balance)
	{
		printf("Insufficient funds, re-enter amount or contact administrator for assistance. \n");
		goto inputTransfer;
	}

	for(int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if(strcmp(p[i].accountID, accountID) == 0)
		{
			accountCurr -> balance -= amountToTransfer;
			p[i].balance += amountToTransfer;
			break;
		}
	}
	
}


/******************************************************************************************
* 	Name:	withdrawMoney
*	Purpose:	To take money out of the current account and physically give it to the user.
*	Parameters:		Account* accountCurr - pointer to the current 
*					account structure information
*				
*	Side effects: Subtract money from the current users account balance.
*******************************************************************************************/
void withdrawMoney(Account* accountCurr)
{
	double amountToWithdraw;
	inputWithdraw:
	printf("Enter amount of money to withdraw: ");
	scanf("%lf", &amountToWithdraw);
	if(amountToWithdraw <= 0)
	{
		printf("Invalid amount:\n");
		goto inputWithdraw;
	}
	
	if(amountToWithdraw > accountCurr -> balance)
	{
		printf("Insufficient funds, re-enter amount or contact administrator for assistance. \n");
		goto inputWithdraw;
	}
	
	
	accountCurr->balance -= amountToWithdraw;
	printf("%lf\n", accountCurr->balance);
}


/******************************************************************************************
* 	Name:	viewAccountInfo
*	Purpose:	To display all of the users information excluding their password.
*	Parameters:		Account* p - pointer to the current 
*					account structure information
*				
*	Side effects: None
*******************************************************************************************/

void viewAccountInfo(Account* p)
{
	printf("First Name: %s\n", p->firstName);
	printf("Last Name: %s\n", p->lastName);
	printf("City: %s\n", p->city);
	printf("State: %s\n", p->state);
	printf("Phone Number: %s\n", p->phoneNumber);
	printf("Account ID: %s\n", p->accountID);
	printf("Balance: %.2f\n\n", p->balance);
}




