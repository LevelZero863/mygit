//
//  main.c
//  project7.1
//
//  Created by EthanLeslie on 2021/9/18.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct poker{
    char* suit;
    char* face;
    struct poker* next;
}poker,*linklist;
int main(int argc, const char * argv[]) {
    // insert code here...
    linklist head=(linklist)malloc(sizeof(poker));
    linklist now=(linklist)malloc(sizeof(poker));
    now=head;
   //每行代表一个face的六种花色(用for循环初始化)
    int face[14][6]={{0,0,0,0,1,1}};
    int i,j;
    for (i=1; i<14; i++) {
        for (j=0; j<6; j++) {
            if(j<=3)
                face[i][j]=1;
            else
                face[i][j]=0;
        }
    }
    char su[6][8]={"spades","hearts","clubs","diamonds","red","black"};
    char fa[14][8]={"Joker","2","3","4","5","6","7","8","9","10","Jack","Queen","King","A"};
    for (i=0; i<54;){
        int s,f;
        f=rand()%14;
        s=rand()%6;
        if(face[f][s]>0){//还没有发牌
            linklist temp=(linklist)malloc(sizeof(poker));
            temp->face=fa[f];
            temp->suit=su[s];
            temp->next=NULL;
            now->next=temp;
            now=temp;
            face[f][s]--;
            i++;
        }
    }
    int flag=1;
    head=head->next;
    i=51;
    while(i>0){
        switch (flag) {
            case 1:
                printf("玩家%d的牌面为%s，花色为%s\n",flag,head->face,head->suit);
                flag++;
                break;
            case 2:
                printf("玩家%d的牌面为%s，花色为%s\n",flag,head->face,head->suit);
                flag++;
                break;
            case 3:
                printf("玩家%d的牌面为%s，花色为%s\n",flag,head->face,head->suit);
                flag=1;
                break;
        }
        head=head->next;
        i--;
    }
    printf("剩余扑克牌为：\n");
    while (head!=NULL) {
        printf("牌面为%s，花色为%s\n",head->face,head->suit);
        head=head->next;
    }
    return 0;
}
