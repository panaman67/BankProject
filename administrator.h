#ifndef ADMIN_H
#define ADMIN_H

#define ADMIN 0
#define CUSTOMER 1
#define MAX_LENGTH_LOGIN 5
#define MAX_CUSTOMERS 100


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


Account* createCustomerAccount();

void changeCustomerInfo(Account p[]);

void changePassword(Account* p);
void viewCustomerInfo(Account p[]);
void deleteCustomerAccount(Account data[]);
void showTopFive(Account data[]);
void showAccountsAlpha(Account data[]);

#endif