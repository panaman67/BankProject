void ViewBalance(Account accountCurr)
{
	double checkBalance = accountCurr -> balance;
	printf("Your balance is: %.2f", checkBalance);
}

void depositMoney(Account accountCurr)
{
	double amountToDeposit;
	
	printf("Enter amount to deposit: ");
	scanf("%.2f", amountToDeposit);
	
	accountCurr -> balance + amountToDeposit;
}

void transferMoney(Account accountCurr)
{
	double amountToTransfer;
	int accountNum;
	
	printf("Enter account number to transfer to");
	scanf("%d", accountNum)
	
	printf("Enter amount to transfer to %d :", accountNum)
	scanf("%.2f", amountToTransfer);
	for(int i = 0; sizeof(accounts)/sizeof(Account); i++)
	{
		if(accountNum == accounts->accountNumber)
		{
			accountCurr -> balance - amountToTransfer;
			accountSec -> balance + amountToTransfer;
		}
	}
}

void withdrawMoney(accountCurr)
{
	double amountToWithdraw;
	
	printf("Enter amount of money to withdraw: ");
	scanf("%.2f", amountToWithdraw);
	
	accountCurr->balance - amountToWithdraw;
}
	
}