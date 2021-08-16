.PHONY:all
all:shm makelib
makelib: comm.o
	gcc comm.c -fPIC -shared -o libsem.so

shm: makelib
	cp libsem.so /lib
	gcc -o server server.c -L. -lsem
	gcc -o client client.c -L. -lsem

.PHONY:clean
clean:
	rm -f server client libsem.so mypipe comm.o
