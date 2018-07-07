old: banksystem.c customer.c administrator.c administrator.h customer.h
	gcc banksystem.c customer.c administrator.c -o banksystem

exp: main.c account.c admin.c user.c account.h admin.h user.h
	clang main.c account.c admin.c user.c -o term
