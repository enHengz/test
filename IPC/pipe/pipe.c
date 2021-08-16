/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * pipe.c
 * Original Author: zhangm@reachxm.com
 */


#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd[2] = {0};
    int ret = -1;
    pid_t id = -1;

    ret = pipe(fd);
    if (ret == -1) {
        fprintf(stdout, "creat pipe error!\n");
        return -1;
    }

    id = fork();
    if(id < 0) {
        fprintf(stdout, "creat fork error!\n");
        close(fd[0]);
        close(fd[1]);

        return -1;
    } else if (id == 0) {
        int i = 0;
        char *child = "I am child!";

        close(fd[0]);

        while (i < 5) {
            write(fd[1], child, strlen(child) + 1);
            sleep(2);

            fprintf(stdout, "client write: %s\n", child);
            i++;
        }
    } else {
        char msg[100];
        int j = 0;
        ssize_t s;

        close(fd[1]);

        while (j < 5) {
            memset(msg, 0, sizeof(msg));

            s = read(fd[0], msg, sizeof(msg));
            if (s > 0) {
                msg[s - 1] = '\0';
            }

            fprintf(stdout, "farther read: %s\n", msg);
            j++;
        }
    }

    return 0;
}