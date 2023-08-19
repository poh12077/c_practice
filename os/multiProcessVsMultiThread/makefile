all : multithread.out multiprocess.out t.out tt.out

tt.out : tt.c
	gcc -o tt.out tt.c -g 

t.out : t.c
	gcc -o t.out t.c -g 

multithread.out : multithread.c
	gcc -o multithread.out multithread.c -g -lpthread

multiprocess.out : multiprocess.c
	gcc -o multiprocess.out multiprocess.c -g
