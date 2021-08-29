/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * main.c
 * Original Author: zhangm@reachxm.com
 */


#include <stdio.h>
#include <string.h>

char *func(void)
{
    int len;
    int i;
    char str[30] = {'0', '1'};

    len = strlen(str);
    printf("len = %d\n", len);

    for (i = 0; i <len; i++) {
        printf("pstr%d] = %c\n", i, str[i]);
    }

    return str;
}

int func1()
{
    int a;

    a = 1;

    return a;
}

int main(void)
{
    char *p;
    int len;
    int i;
    int result;

    p = func();
    printf("p = %s\n", p);

    len = strlen(p);
    printf("len = %d\n", len);

    for (i = 0; i <len; i++) {
        printf("p[%d] = %c\n", i, p[i]);
    }

    result = func1();
    printf("result is %d\n", result);

    return 0;
}