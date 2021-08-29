/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * main.c
 * Original Author: zhangm@reachxm.com
 */


#include <stdio.h>

int main(void)
{
    int k;
    unsigned int z;
    int i = -20;
    unsigned int j = 10;
    unsigned int t = -10;
    unsigned int m;

    k = i + j;
    printf("int k = %d\n", k);
    printf("int k = %u\n", k);
    z = i + j;
    printf("unsigned int z = %d\n", z);
    printf("unsigned int z = %u\n", z);

    m = 9;
    printf("m unsigned is %u\n", m);
    printf("m int is %d\n", m);

    if (m >= 0) {
        printf("m is %u\n", m);
    }

    m--;
    printf("m unsigned is %u\n", m);
    printf("m int is %d\n", m);

#if 1
    for (m = 9; m >= 0; m--) {
        printf("m is %u\n", m);
    }
#endif

    return 0;
}