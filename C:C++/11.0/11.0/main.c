//
//  main.c
//  11.0
//
//  Created by EthanLeslie on 2021/9/22.
//
#include <stdio.h>
#include <string.h>
//#include "Queue.h"
typedef struct queue{
    char name[20][50];
    int front;
    int rear;
}QUEUE,*Pqueue;
void EnQueue(Pqueue q,char name[]);
char* DeQueue(Pqueue q);
void InitQueue(Pqueue man,Pqueue woman);
int main(int argc, const char * argv[]) {
    // insert code here...
    QUEUE queue1,queue2;
    queue1.front=0;
    queue1.rear=0;
    queue2.front=0;
    queue2.rear=0;
    Pqueue manQueue=&queue1;
    Pqueue womanQueue=&queue2;
    InitQueue(manQueue,womanQueue);
    int len1=manQueue->rear;
    int len2=womanQueue->rear;
    int len = len1<len2?len1:len2;
    int i,j;
    printf("请输入舞会的轮数：\n");
    int n;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        for (j=0; j<len; j++) {
            char person1[50];
            char person2[50];
            strcpy(person1, DeQueue(manQueue));
            strcpy(person2, DeQueue(womanQueue));
            printf("配对的舞者：%s %s\n",person1,person2);
            EnQueue(manQueue, person1);
            EnQueue(womanQueue, person2);
        }
        if (len1>len2) {
            printf("第一个出场的未配对舞者的姓名：%s\n",manQueue->name[manQueue->front]);
        }else{
            printf("第一个出场的未配对舞者的姓名：%s\n",womanQueue->name[womanQueue->front]);
        }
    }
    return 0;
}
void EnQueue(Pqueue q,char name[])
{
    strcpy(q->name[q->rear], name);
    q->rear=(q->rear+1)%20;
}
char* DeQueue(Pqueue q){
    char *d = q->name[q->front];
    q->front = (q->front+1)%20;
    return d;
}
void InitQueue(Pqueue man,Pqueue woman){
    int manNum=0,womanNum=0;
    printf("请输入男队人数：\n");
    scanf("%d",&manNum);

    int i;
    printf("请输入男队姓名：\n");
    for (i=0; i<manNum; i++) {
        scanf("%s",man->name[i]);
        man->rear=(man->rear+1)%20;
    }
    
    printf("请输入女队人数：\n");
    scanf("%d",&womanNum);
    printf("请输入女队姓名：\n");
    for (i=0; i<womanNum; i++) {
        scanf("%s",woman->name[i]);
        woman->rear=(woman->rear+1)%20;
    }
}
