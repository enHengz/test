/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * main.c
 * Original Author: zhangm@reachxm.com
 */


#include <stdio.h>

static int j;

void fun1(void)
{
    static int i = 0;       /* 这是一个定义，内存的静态区，函数运行结束它还在*/
    i++;
    printf("i = %d\n", i);
}

void fun2(void)
{
    j = 0;
    j++;
    printf("j = %d\n", j);
}

void fun3(void)
{
    static int i = 0;
    i++;
    printf("k = %d\n", i);
}

int main(void)
{
    int k;

    for (k = 0; k < 10; k++) {
        fun1();
        fun2();
        fun3();
    }

    return 0;
}