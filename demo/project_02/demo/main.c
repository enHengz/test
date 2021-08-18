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

    k = i + j;
    printf("int k = %d\n", k);
    printf("int k = %u\n", k);
    z = i + j;
    printf("unsigned int z = %d\n", z);
    printf("unsigned int z = %u\n", z);

    return 0;
}