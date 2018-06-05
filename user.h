#ifndef USER_H
#define USER_H


void ChangePassword(node Account, char* newPassword);
void Deposit(node Account, float amt);
void Withdraw(node Account, float amt);
void Transfer(node Account, float amt);
void ModifyInfo(node Account);


#endif
