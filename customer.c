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
	scanf("%.2f", amountToDeposit);
	
	accountCurr -> balance += amountToDeposit;
}

void transferMoney(Account* accountCurr, Account p[])
{
	double amountToTransfer;
	char accountNum[6];
	
	printf("Enter account number to transfer to");
	scanf("%s", accountNum)
	
	printf("Enter amount to transfer to %s :", accountNum);
	scanf("%.2f", amountToTransfer);
	for(int i = 0; MAX_CUSTOMERS; i++)
	{
		if(accountNum == accounts->accountNumber)
		{
			accountCurr -> balance - amountToTransfer;
			accountSec -> balance + amountToTransfer;
		}
	}
}

void withdrawMoney(Account* accountCurr)
{
	double amountToWithdraw;
	
	printf("Enter amount of money to withdraw: ");
	scanf("%.2f", amountToWithdraw);
	
	accountCurr->balance - amountToWithdraw;
}
	
}