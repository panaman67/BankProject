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
	
	printf("Enter amount to deposit: ");

	scanf("%f", amountToDeposit);

	
	accountCurr -> balance += amountToDeposit;
}

//function to transfer money
void transferMoney(Account* accountCurr, Account p[])
{
	double amountToTransfer;
	char accountNum[6];
	
	printf("Enter account number to transfer to");
	scanf("%s", accountNum);
	
	printf("Enter amount to transfer to %s :", accountNum);

	scanf("%f", amountToTransfer);

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
	
	printf("Enter amount of money to withdraw: ");


	scanf("%f", amountToWithdraw);
	
	accountCurr->balance -= amountToWithdraw;
}
