/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * client.c
 * Original Author: zhangm@reachxm.com
 */


#include "comm.h"

int main()
{
    int shmid = GetShmid(4097);
    if (shmid > 0) {
        int i = 0;
        char *addr = shmat(shmid, NULL, 0);

        while (i < 20) {
            printf("%s\n", addr);
            sleep(1);
            i++;
        }

        if (shmdt(addr) == -1) {
            perror("shmdt");
            return -1;
        }
    } else {
        perror("GetShmid");
        return -2;
    }

    return 0;
}