/*
Name: Nicholas Paladino
      James Sigler
	  
Section: 502
Purpose: To create functions and give the their functionality 
	 when accessing the user account type in main menu
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//include header files
#include "customer.h"

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
	
	//making sure the deposit amount is valid
	if((amountToDeposit <= 0) || (amountToDeposit > MAX_TRANSACTION))
	{
		printf("Invalid deposit amount\n");
		//repeating if not valid
		goto inputDeposit;
	}
	
	//adding the deposit to the balance
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
	//accessing other account's ID
	printf("Enter account number to transfer to: ");
	scanf("%s", accountID);
	
	
	//making sure that money will not transfer to the same account
	if (strcmp(accountID, accountCurr -> accountID) == 0)
	{
		printf("\n Cannot transfer to same account, please enter a valid user ID. \n");
		goto inputID;
	}
	
	//making sure the account to transfer to is valid
	for(int n = 0; n < strlen(accountID); n++)
	{
		if((strlen(accountID) > 5) || (isdigit(accountID[n]) == false))
		{
			printf("Invalid account ID\n");
			goto inputID;
		}
	}
	
	inputTransfer:
	printf("Enter amount to transfer to %s : ", accountID);
	scanf("%lf", &amountToTransfer);
	
	
	//making sure they are transfering a valid amount of money
	if(amountToTransfer <= 0 || amountToTransfer > MAX_TRANSACTION)
	{
		printf("Invalid amount\n");
		goto inputTransfer;
	}
	
	//making sure the user cannot give more than they have
	if(amountToTransfer > accountCurr -> balance)
	{
		printf("Insufficient funds, re-enter amount or contact administrator for assistance. \n");
		goto inputTransfer;
	}

	//checking every user for the correct account to transfer to
	for(int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if(strcmp(p[i].accountID, accountID) == 0)
		{
			//subtracting the amount from the current account
			accountCurr -> balance -= amountToTransfer;
			
			//adding the amount to the specified account
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
	
	//entering amount to withdraw
	printf("Enter amount of money to withdraw: ");
	scanf("%lf", &amountToWithdraw);

	//making sure the user withdraws a positive number
	if(amountToWithdraw <= 0)
	{
		printf("Invalid amount\n");
		goto inputWithdraw;
	}
	
	//making sure they do not withdraw more than they have
	if(amountToWithdraw > accountCurr -> balance)
	{
		printf("Insufficient funds, re-enter amount or contact administrator for assistance. \n");
		goto inputWithdraw;
	}
	
	//subtracting the money from their balance
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
	printf("\nFirst Name: %s\n", p->firstName);
	printf("Last Name: %s\n", p->lastName);
	printf("City: %s\n", p->city);
	printf("State: %s\n", p->state);
	printf("Phone Number: %s\n", p->phoneNumber);
	printf("Account ID: %s\n", p->accountID);
	printf("Balance: %.2f\n\n", p->balance);
}
