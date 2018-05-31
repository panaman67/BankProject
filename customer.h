//Name: Nicholas Paladino
//		James Sigler
//Section: 502
//Purpose: To declare function prototypes for customer.c file

//header file protection
#ifndef CUST_H
#define CUST_H

//include admin header for Account struct use
#include "administrator.h"

//function prototypes
void ViewBalance(Account* accountCurr);
void depositMoney(Account* accountCurr);
void transferMoney(Account* accountCurr, Account p[]);
void withdrawMoney(Account* accountCurr);
void viewAccountInfo(Account* p);

//end header protection
#endif
