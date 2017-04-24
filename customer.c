#include <stdio.h>
#include "customer.h"
#include "administrator.h"
#include <string.h>

void ViewBalance(Account* accountCurr)
{
	printf("Your balance is: %.2f\n", accountCurr -> balance);
}

void depositMoney(Account* accountCurr)
{
	double amountToDeposit;
	
	printf("Enter amount to deposit: ");
<<<<<<< HEAD
	scanf("%lf", &amountToDeposit);
=======
	scanf("%f", amountToDeposit);
>>>>>>> parent of 9d1b138... Fixed some stuff
	
	accountCurr -> balance += amountToDeposit;
}

void transferMoney(Account* accountCurr, Account p[])
{
	double amountToTransfer;
	char accountNum[6];
	
	printf("Enter account number to transfer to");
	scanf("%s", accountNum);
	
	printf("Enter amount to transfer to %s :", accountNum);
<<<<<<< HEAD
	scanf("%lf", &amountToTransfer);
=======
	scanf("%f", amountToTransfer);
>>>>>>> parent of 9d1b138... Fixed some stuff
	for(int i = 0; i < MAX_CUSTOMERS; i++)
	{
		if(strcmp(p[i].accountID, accountNum) == 0)
		{
			accountCurr -> balance -= amountToTransfer;
			p[i].balance += amountToTransfer;
		}
	}
}


void withdrawMoney(Account* accountCurr)
{
	double amountToWithdraw;
	
	printf("Enter amount of money to withdraw: ");
<<<<<<< HEAD
	scanf("%lf", &amountToWithdraw);
=======
	scanf("%f", amountToWithdraw);
>>>>>>> parent of 9d1b138... Fixed some stuff
	
	accountCurr->balance -= amountToWithdraw;
}
