//
//  Delete.c
//  project9.0
//
//  Created by EthanLeslie on 2021/9/22.
//

#include "Delete.h"
#include "CreateList.h"
#include <stdlib.h>
void delete(linklist head){
    int index;
    printf("请输入要删除的节点位置：\n");
    scanf("%d",&index);
    linklist now = head;
    int i=0;
    while (now!=NULL) {
        if(i==index){
            linklist delete = now->next;
            now->next=now->next->next;
            free(delete);
            printf("已删除！\n");
            break;
        }
        i++;
        now=now->next;
    }
    printf("新的链表内容为：\n");
    now=head->next;
    while (now!=NULL) {
        printf("%d\n",now->data);
        now=now->next;
    }
}
