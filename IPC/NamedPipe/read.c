/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * read.c
 * Original Author: zhangm@reachxm.com
 */


#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
 
int main(){
    int ret,fd;
    char  buf[20] = "";
    const char* path = "./testfifo1";
    const int pre = O_RDONLY;

    fd = open(path,pre);
    if (fd == -1){
        perror("open error");
        exit(-1);
    }

	for ( ; ; ) {
        ret = read(fd, buf, sizeof(buf));
        if (ret > 0) {
            printf("read : %s\n",buf);
        }

        sleep(1);
    }
 
    return 0; 
}