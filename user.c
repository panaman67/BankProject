#include <stdio.h>
#include "account.h"
#include "user.h"

void Deposit(Node acc, float amt)
{
	printf("Depositing money into acc: %d\n"
		"Before: %.2f", acc->accID, acc->balance);
	acc->balance += amt;
	printf("After: %.2f", acc->balance);
}
