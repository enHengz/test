/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * client.c
 * Original Author: zhangm@reachxm.com
 */


#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
 
#define SERVERNAME "myserver"
 
int main(void)
{
    struct sockaddr_un client;
    int fd;
    int result = 0;

    fd = socket(AF_UNIX, SOCK_STREAM, 0);

    client.sun_family = AF_UNIX;
    strcpy(client.sun_path, SERVERNAME);

    bind(fd, (struct sockaddr *)&client, sizeof(client));

    result = connect(fd,(struct sockaddr *)&client, sizeof(client));
    if (result < 0){
        printf("error in connect\n");
        return 0;
    }

    write(fd, "hello world", 15);
}
