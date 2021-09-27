//
//  CreateList.h
//  project9.0
//
//  Created by EthanLeslie on 2021/9/22.
//

#ifndef CreateList_h
#define CreateList_h

#include <stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}node,*linklist;
void creatlist(linklist head);
#endif /* CreateList_h */
