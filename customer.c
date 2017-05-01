#include <stdio.h>
#include <string.h>
//include header files
#include "customer.h"
#include "administrator.h"

//function for viewing balence
void ViewBalance(Account* accountCurr)
{
	printf("Your balance is: %.2f\n", accountCurr -> balance);
}

//function for depositimg money
void depositMoney(Account* accountCurr)
{
	double amountToDeposit;
	
	inputDeposit:
	printf("Enter amount to deposit(maximum of $5000): ");
	scanf("%f", amountToDeposit);
	if((amountToDeposit <= 0) || (amountToDeposit > 5000))
	{
		printf("Invalid deposit amount");
		goto inputDeposit;
	
	accountCurr -> balance += amountToDeposit;
}

//function to transfer money
void transferMoney(Account* accountCurr, Account p[])
{
	double amountToTransfer;
	char accountID[6];
	
	inputID:
	printf("Enter account number to transfer to");
	scanf("%s", accountID);
	for(int n = 0; n <= strlen(accountID); n++)
	{
		if((strlen(accountID) > 5) || (isdigit(accountID[n]) == False))
		{
			printf("Invalid account ID\n");
			goto inputID;
		}

	inputTransfer:
	printf("Enter amount to transfer to %s :", accountNum);
	scanf("%f", amountToTransfer);
	
	if(amountToTransfer <= 0)
	{
		printf("Invalid amount:\n");
		goto inputTransfer;
	}

	for(int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if(strcmp(p[i].accountID, accountNum) == 0)
		{
			accountCurr -> balance -= amountToTransfer;
			p[i].balance += amountToTransfer;
		}
	}
}

//function to withdraw money
void withdrawMoney(Account* accountCurr)
{
	double amountToWithdraw;
	inputWithdraw:
	printf("Enter amount of money to withdraw: ");
	scanf("%f", amountToWithdraw);
	if(amountToWithdraw <= 0)
	{
		printf("Invalid amount:\n");
		goto inputWithdraw;
	}
	
	
	accountCurr->balance -= amountToWithdraw;
}
