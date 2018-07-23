#ifndef USER_H
#define USER_H

#include "account.h"

void ChangePassword(Node Account, char* newPassword);
void Deposit(Node Account, float amt);
void Withdraw(Node Account, float amt);
void Transfer(Node Account, float amt);
void ModifyInfo(Node Account);

#endif
