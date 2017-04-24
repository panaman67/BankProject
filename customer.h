#ifndef CUST_H
#define CUST_H

#include "administrator.h"

void ViewBalance(Account* accountCurr);
void DepositMoney(Account* accountCurr);
void TransferMoney(Account* accountCurr, Account p[]);
void WithdrawMoney(Account* accountCurr);





#endif