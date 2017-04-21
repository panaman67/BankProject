#include <stdio.h>
#include "administrator.c"
#include "customer.c"

#define ADMIN 0
#define CUSTOMER 1
#define MAX_LENGTH_LOGIN 5
#define MAX_CUSTOMERS 100

typedef struct
{
	char status;
	char firstName[9], lastName[9];
	char city[11];
	char state[3];
	char phoneNumber[9];
	int accountNumber;
	char password[7];
	double balance;
} Account;


void DisplayMenu(int mode);
void LoadCustomers(FILE* input, Account p[]);


int main(int argc, char* argv[])
{
	char ID[MAX_LENGTH_LOGIN + 1], password[MAX_LENGTH_LOGIN + 1];
	FILE* data;
	
	data = fopen("CustomerData.txt", "r+");
	
	
	Account accounts[MAX_CUSTOMERS];
	
	printf("Welcome to Online Banking/ATM System\n");
	printf("====================================\n\n");
	
	printf("Enter your Customer/Admin ID: ");
	scanf("%5s", ID);
	ID[MAX_LENGTH_LOGIN] = '\0';
	
	printf("Enter your Customer/Admin Password: ");
	scanf("%5s", password);
	password[MAX_LENGTH_LOGIN] = '\0';
	
	LoadCustomers(data, accounts);
	
	fclose(data);
	return 0;
}

void LoadCustomers(FILE* input, Account p[])
{
	
	fscanf(input, "%c %s %s %s %s %d %s %f", &p[0].status,
											  p[0].firstName,
											  p[0].lastName,
											  p[0].city,
											  p[0].state,
											  p[0].phoneNumber,
											 &p[0].accountNumber,
											  p[0].password,
											 &p[0].balance);
	//printf("%c\n\n\n", p[0].status);
	
}


void DisplayMenu(int mode)
{
	if (mode == ADMIN)
	{
		printf("--------------------\n");
		printf("Administrator Menu\n");
		printf("--------------------\n");
		printf("1)  Create Customer account\n");
		printf("2)  Change Password\n");
		printf("3)  View Customer Info\n");
		printf("4)  Change Customer Info\n");
		printf("5)  Delete Customer account\n");
		printf("6)  Show Top 5 accounts\n");
		printf("7)  Show customer accounts alphabetically\n");
		printf("8)  Exit\n");
	}
	else if (mode == CUSTOMER)
	{
		printf("--------------------\n");
		printf("Customer Menu\n");
		printf("--------------------\n");
		printf("a)  Change Password\n");
		printf("b)  View Customer information\n");
		printf("c)  View Balance\n");
		printf("d)  Make a Deposit\n");
		printf("e)  Transfer Money\n");
		printf("f)  Withdraw Money\n");
		printf("g)  Exit\n");
	}
}