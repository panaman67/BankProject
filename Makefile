Makefile: banksystem.c customer.c administrator.c administrator.h customer.h
	gcc banksystem.c customer.c administrator.c -o banksystem

exp: linktest.c account.c account.h
	clang linktest.c account.c
