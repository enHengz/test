/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * server.c
 * Original Author: zhangm@reachxm.com
 */


#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
 
#define SERVERNAME   "myserver"
 
void sig_chld(int signo)
{
    pid_t pid;
    int stat;
 
    while((pid = waitpid(-1, &stat, WNOHANG))>0)
        printf("child %d terminated\n", pid);
    return;
}
 
int main(void)
{
    struct sockaddr_un server, client;
    int serverfd, clientfd;
    char data[64] = {0};
    pid_t pid;
 
    serverfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(serverfd < 0){
        printf("error in socket\n");
        exit(0);
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SERVERNAME);
 
    unlink(SERVERNAME);
    
    if (bind(serverfd,(struct sockaddr*)&server, sizeof(server)) < 0){
        printf("error in bind\n");
        return 0;
    }
 
    listen(serverfd, 5);
    signal(SIGCHLD, sig_chld);
    while (1) {
        socklen_t socket_len = sizeof(client);
        clientfd = accept(serverfd,(struct sockaddr *)&client, &socket_len);
        if (clientfd < 0){
                printf("error clientfd\n");
                return 0;
        }

        if((pid = fork()) == 0){
            read(clientfd, data, 30);
            printf("\nrcv:%s\n", data);
            exit(0);
        }
 
    }
 
    unlink(SERVERNAME);

    return 0;
}
