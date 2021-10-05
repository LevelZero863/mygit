//
//  main.c
//  project13.0
//
//  Created by EthanLeslie on 2021/10/4.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char vexs[10];
    int am[10][10];
    int vnum, edgenum;
}Graph;
typedef struct{
    char data[10];
    int front;
    int rear;
}Queue;
void EnQueue(Queue *Q, char d){
    Q->data[Q->rear] = d;
    Q->rear = (Q ->rear + 1) % 10;
}

char DeQueue(Queue *Q){
    char a = Q->data[Q ->front];
    Q->front = (Q ->front + 1) % 10;
    return a;
}

int getQueue(Queue *Q){
    if(Q->front == Q->rear){
        return 1;
    }else{
        return 0;
    }
}
Graph initGraph(Graph G){
    printf("输入顶点个数：");
    scanf("%d",&G.vnum);
    printf("请输入顶点:");
    for(int i = 0;i < G.vnum;i ++){
        scanf(" %c", &G.vexs[i]);
    }
    printf("\n请输入边数:");
    scanf("%d", &G.edgenum);
    for(int i = 0;i < 10;i ++){
        for(int j = 0;j < 10;j ++){
            G.am[i][j] = 0;
        }
    }
    for(int i = 0;i < G.edgenum;i ++){
        char v1, v2;
        int V1, V2;
        printf("请输入边：");
        scanf(" %c%c",&v1,&v2);
        switch(v1){
            case 'A':V1 = 0;break;
            case 'B':V1 = 1;break;
            case 'C':V1 = 2;break;
            case 'D':V1 = 3;break;
            case 'E':V1 = 4;break;
            case 'F':V1 = 5;break;
            case 'G':V1 = 6;break;
            case 'H':V1 = 7;break;
            case 'I':V1 = 8;break;
            default:V1 = 9;break;
        }
        switch(v2){
            case 'A':V2 = 0;break;
            case 'B':V2 = 1;break;
            case 'C':V2 = 2;break;
            case 'D':V2 = 3;break;
            case 'E':V2 = 4;break;
            case 'F':V2 = 5;break;
            case 'G':V2 = 6;break;
            case 'H':V2 = 7;break;
            case 'I':V2 = 8;break;
            default:V2 = 9;break;
        }
        G.am[V1][V2] = 1;
        G.am[V2][V1] = 1;
    }
    return G;
}
void DFS(Graph G, int flag[], int i){
    printf("%c", G.vexs[i]);
    flag[i] = 1;
    for(int j = 0;j < G.vnum;j ++){
        if(G.am[i][j] == 1 && flag[j] == 0){
            DFS(G, flag,j);
        }
    }
}
void DFSTravers(Graph G, int flag[]){
    for(int i = 0;i < G.vnum;i ++){
        flag[i] = 0;
    }
    for(int i = 0;i < G.vnum;i ++){
        if(flag[i] == 0){
            DFS(G, flag, i);
        }
    }

}
void BFS(Graph G,int flag[]){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    for(int i = 0;i < G.vnum;i ++){
        if(flag[i] == 0){
            printf("%c", G.vexs[i]);
            flag[i] == 1;
            EnQueue(q, G.vexs[i]);
            while(getQueue(q) == 0){
                char c = DeQueue(q);
                for(int j = 0;j < G.vnum;j ++){
                    if(G.am[i][j] == 1 && flag[j] == 0){
                        printf("%c", G.vexs[j]);
                        flag[j] = 1;
                        EnQueue(q, G.vexs[j]);
                    }
                }
            }
        }
    }
}
int main()
{
    Graph G;
    int flag[10] = {0};
    G = initGraph(G);
    printf("深度优先遍历为：");
    DFSTravers(G, flag);
    printf("\n");
    for(int i = 0;i < 10;i ++){
        flag[i] = 0;
    }
    printf("广度优先遍历为：");
    BFS(G,flag);
    return 0;
}
