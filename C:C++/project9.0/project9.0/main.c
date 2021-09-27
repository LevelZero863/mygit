//
//  main.c
//  project9.0
//
//  Created by EthanLeslie on 2021/9/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "CreateList.h"
#include "Insert.h"
#include "Delete.h"
#include "PrintNode.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    linklist head = (linklist)malloc(sizeof(node));
    head->next=NULL;
    creatlist(head);
    while(1){
        printf("***********请选择要执行的操作**************\n");
        printf("1.插入节点\n2.删除节点\n3.节点显示\n***************************\n");
        int choose;
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                insert(head);
                break;
            case 2:
                delete(head);
                break;
            case 3:
                printnode(head);
                break;
            default:
                return 0;
        }
    }
    return 0;
}
