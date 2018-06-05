Makefile: banksystem.c customer.c administrator.c administrator.h customer.h
	gcc banksystem.c customer.c administrator.c -o banksystem
