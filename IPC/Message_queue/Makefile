.PHONY:all
all:msgreceive msgsend
msgreceive:msgreceive.c 
	gcc -o $@ $^

msgsend:msgsend.c 
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f msgreceive msgsend mypipe
