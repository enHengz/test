/*
 * Copyright(c) 2021 zhangm All rights reserved.
*/
/*
 * server.c
 * Original Author: 942202623@qq.com 2021-08-15
 *
 * 
 */


#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char** argv)
{
    int  sockfd, n;
    char recvline[100 + 1];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        printf("usage: a.out <IPaddress>");
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error");
    }

	printf("start set!\n");
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s", argv[1]);
    }

    if (connect(sockfd, &servaddr, sizeof(servaddr)) < 0) {
        printf("connect error");
    }

    while ((n = read(sockfd, recvline, 100)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF) {
            printf("fputs error");
        }
    }

    if (n < 0) {
        printf("read error");
    }

    return 0;
}