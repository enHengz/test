/*
 * Copyright(c) 2021 zhangm All rights reserved. 
 */
/*
 * memory-alignment.c
 * Original Author: 942202623@qq.com, 2021-08-15
 *
 * Just an example of looking at memory
 */


#include <stdio.h>
#include <stddef.h>

typedef struct test{
    int a;
    double b;
    float c;
}Test;

typedef struct test1{
    char a[2];
    int b;
    double c;
    short d;
    Test e;
}Test1;

int main(int argc, char** argv)
{
    Test1 T;

    int offset_a = offsetof(Test1, a);
    int offset_b = offsetof(Test1, b);
    int offset_c = offsetof(Test1, c);
    int offset_d = offsetof(Test1, d);
    int offset_e = offsetof(Test1, e);

    printf("The length of char type is %u\n", sizeof(char));
    printf("The length of int type is %u\n", sizeof(int));
    printf("The length of double type is %u\n", sizeof(double));
    printf("The length of short type is %u\n", sizeof(short));
    printf("The length of Test type is %u\n\n", sizeof(Test));

    printf("The length of the whole struct is %u\n\n", sizeof(T));

    printf("The offset of first data member is %d\n", offset_a);
    printf("The offset of second data member is %d\n", offset_b);
    printf("The offset of third data member is %d\n", offset_c);
    printf("The offset of fourth data member is %d\n", offset_d);
    printf("The offset of fifth data member is %d\n\n", offset_e);

    printf("The begin address of first data member of struct test is %p\n", &(T.a));
    printf("The begin address of second data member of struct test is %p\n", &(T.b));
    printf("The begin address of third data member of struct test is %p\n", &(T.c));
    printf("The begin address of third data member of struct test is %p\n", &(T.d));
    printf("The begin address of third data member of struct test is %p\n\n", &(T.e));

    return 0;
}
