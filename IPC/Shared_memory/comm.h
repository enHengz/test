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
#include <error.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PATHNAME "."
#define PROJ_ID 066

int CreatShmid(int size);
int GetShmid(int size);
int Destory(int shmid);

#endif /* __COMM_H__ */