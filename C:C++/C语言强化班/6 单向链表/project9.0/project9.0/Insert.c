//
//  Insert.c
//  project9.0
//
//  Created by EthanLeslie on 2021/9/22.
//

#include "Insert.h"
#include "CreateList.h"
#include <stdio.h>
#include <stdlib.h>
void insert(linklist head){
    int index,num;
    linklist now=head;
    printf("请输入插入位置：\n");
    scanf("%d",&index);
    printf("请输入插入数字：\n");
    scanf("%d",&num);
    int i=0;
    while (now!=NULL) {
        if (i==index) {
            linklist temp = (linklist)malloc(sizeof(node));
            temp->data=num;
            temp->next=now->next;
            now->next=temp;
            break;
        }
        now=now->next;
        i++;
    }
    printf("新的链表内容为：\n");
    now=head->next;
    while (now!=NULL) {
        printf("%d\n",now->data);
        now=now->next;
    }
}
