.PHONY:all
all:mkfifo read write
mkfifo:mkfifo.c 
	gcc -o $@ $^

write:write.c 
	gcc -o $@ $^

read: read.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f mkfifo write read mypipe testfifo1
