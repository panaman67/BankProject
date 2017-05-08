/*
Names:   Nicholas Paladino
	     James Sigler
Section: 502
Purpose: To declare function prototypes for admin
		 and to define Account struct
*/

//header file protection
#ifndef ADMIN_H
#define ADMIN_H

//define constants
#define ADMIN 1
#define CUSTOMER 2
#define MAX_LENGTH_LOGIN 5
#define MAX_CUSTOMERS 100

//define structure for account
typedef struct
{
	int status;
	char firstName[9], lastName[9];
	char city[11];
	char state[3];
	char phoneNumber[9];
	char accountID[6];   //MAX 5 digits
	char password[7];
	double balance;
} Account;

//function prototypes
void CreateCustomerAccount(Account data[], int pos, int* accNum);
void ChangePassword(Account* p);
void ViewCustomerInfo(Account data[]);
void ChangeCustomerInfo(Account data[]);
void DeleteCustomerAccount(Account data[], int numAccounts);
void ShowTopFive(Account data[]);
void ShowAccountsAlpha(Account data[]);

//end header protection 
#endif