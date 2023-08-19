CC =gcc

a.out : main.o libfunc.a
	gcc -o a.out main.o -L. -lfunc

libfunc.a : libfunc.o
	ar crv libfunc.a libfunc.o

libfunc.o : libfunc.c
	gcc -g -c libfunc.c

main.o : main.c
	gcc -g -c main.c


clean :
	rm *.o 
