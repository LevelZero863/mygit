//
//  CreateList.c
//  project9.0
//
//  Created by EthanLeslie on 2021/9/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "CreateList.h"
void bubble(linklist phead, int len) {
    linklist ptr,next;
    int temp;
    int i,j;
    for(i = 0; i < len; i++) {
        ptr = phead->next;
        next = ptr->next;
        for(j = len - i - 1; j > 0; j--) {
            if(ptr->data > next->data) {
                temp = ptr->data;
                ptr->data = next->data;
                next->data = temp;
            }
            ptr = ptr->next;
            next = next->next;
        }
    }
}
void creatlist(linklist head){
    int length;
    printf("请输入链表长度：\n");
    scanf("%d",&length);
    int i;
    linklist now = head;
    for (i=0; i<length; i++) {
        linklist temp = (linklist)malloc(sizeof(node));
        int num;
        printf("请输入第%d个数字：\n",i+1);
        scanf("%d",&num);
        temp->data=num;
        temp->next=NULL;
        now->next=temp;
        now=temp;
    }
    bubble(head, length);
}
