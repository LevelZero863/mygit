//
//  PrintNode.c
//  project9.0
//
//  Created by EthanLeslie on 2021/9/22.
//

#include "PrintNode.h"
#include "CreateList.h"

void printnode(linklist head){
    int index;
    printf("请输入要显示节点位置:\n");
    scanf("%d",&index);
    linklist now=head;
    int i=0;
    while (now!=NULL) {
        if(i==index){
            printf("该节点内容为：%d\n",now->next->data);
            return;
        }
        i++;
        now=now->next;
    }
}
