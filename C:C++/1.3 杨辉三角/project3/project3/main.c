//
//  main.c
//  project3
//
//  Created by EthanLeslie on 2021/9/15.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node* next;
}link,*linklist;
int main(int argc, const char * argv[]) {
    int i;
    int line;
    scanf("%d",&line);
    linklist before;
    linklist head;
    linklist a=(linklist)malloc(sizeof(link));
    linklist b=(linklist)malloc(sizeof(link));
    before=a;
    a->value=1;
    b->value=1;
    a->next=b;
    b->next=NULL;
    for (i=1; i<=line; i++) {
        if(i==1) {
            printf("1\n");
            continue;
        }
        if(i==2){
            printf("1 1\n");
            continue;
        }
        linklist now=(linklist)malloc(sizeof(link));
        head = now;
        now->value=1;
        now->next=NULL;
        printf("%d ",now->value);
        int j;
        for(j=0;j<i-2;j++){
            linklist ll = (linklist)malloc(sizeof(link));
            ll->value=before->value+before->next->value;
            ll->next=NULL;
            before=before->next;
            now->next=ll;
            now=ll;
            printf("%d ",ll->value);
        }
        linklist rear=(linklist)malloc(sizeof(link));
        rear->value=1;
        rear->next=NULL;
        now->next=rear;
        before=head;
        printf("1\n");
    }
    return 0;
    
}
