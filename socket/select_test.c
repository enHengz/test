#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/types.h>
 
int main()
{
    struct timeval tv;              // 超时时间
	tv.tv_sec = 10;
    tv.tv_usec = 500;               // 注意单位是微秒
 
    fd_set rdfds;
    FD_ZERO(&rdfds);                // 描述集初始化
    FD_SET(STDIN_FILENO, &rdfds);   // STDIN_FILENO是标准输入， 塞入描述集

    int iRet = select(STDIN_FILENO + 1, &rdfds, NULL, NULL, &tv);  // 注意注意
    if(iRet < 0)
	{
		printf("selcet error, iRet %d\n", iRet);
		return -1;
	}
 
   	if(0 == iRet)
	{
		printf("timeout \n");
	}
 
	printf("iRet = %d \n", iRet); 
	
	return 0;
}