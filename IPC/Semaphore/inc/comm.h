/*
 * Copyright(C) 2020  Reach All rights reserved.
 */
/*
 * comm.h
 * Original Author: zhangm@reachxm.com
 */

#ifndef __COMM_H__
#define __COMM_H__


#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <error.h>

#define  PATHNAME "."
#define  PROJ_ID  0

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *arry;
    struct seminfo *__buf;
};

static int CommSemid(int nums, int flags);

int CreatSemid(int nums);

int GetSemid(int nums);

int InitSem(int semid, int which, int _val);

static int SemPV(int semid, int which, int _op);

int P(int semid, int which, int _op);

int V(int semid, int which, int _op);

int Destory(int semid);

#endif " __COMM_H__c "