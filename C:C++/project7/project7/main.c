//
//  main.c
//  project7
//
//  Created by EthanLeslie on 2021/9/17.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    //每行代表一个face的六种花色(用for循环初始化)
    //每一行的数字依次代表“spades","hearts","clubs","diamonds","red","black"
    //0～13行依次代表"Joker","2","3","4","5","6","7","8","9","10","Jack","Queen","King","A"
    //1代表该牌还没有发，0表示已经发了
    int face[14][6]={{0,0,0,0,1,1}};
    char su[6][8]={"spades","hearts","clubs","diamonds","red","black"};
    char fa[14][8]={"Joker","2","3","4","5","6","7","8","9","10","Jack","Queen","King","A"};
    int i,j;
    for (i=1; i<14; i++) {
        for (j=0; j<6; j++) {
            if(j<=3)
                face[i][j]=1;
            else
                face[i][j]=0;
        }
    }
    //用for循环每次随机产生两个数，一个数范围是0～13，一个数范围是0～5，代表不同扑克牌
    int flag=1;
    int count=51;
    while(count>0) {
        int s,f;
        s=rand()%6;
        f=rand()%14;
        if(face[f][s]>0){//还没有发牌
            count--;
            switch (flag) {
                case 1:
                    printf("玩家1的牌：花色为%s，牌面为%s\n",su[s],fa[f]);
                    flag++;
                    break;
                case 2:
                    printf("玩家2的牌：花色为%s，牌面为%s\n",su[s],fa[f]);
                    flag++;
                    break;
                case 3:
                    printf("玩家3的牌：花色为%s，牌面为%s\n",su[s],fa[f]);
                    flag=1;
                    break;
            }
            face[f][s]--;
        }
        
    }
    printf("剩余牌为：\n");
    for (i=0; i<14; i++) {
        for (j=0; j<6; j++) {
            if (face[i][j]>0) {
                printf("牌面为%s，花色为%s\n",fa[i],su[j]);
            }
        }
    }
    return 0;
}
