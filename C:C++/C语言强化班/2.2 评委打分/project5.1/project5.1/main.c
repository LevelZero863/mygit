//
//  main.c
//  project5.1
//
//  Created by EthanLeslie on 2021/9/15.
//

#include <stdio.h>
void delete(int* grades);
int main(int argc, const char * argv[]) {
    int grades[5][5];
    int i,j;
    //输入成绩
    for(i=0;i<5;i++){
        for (j=0; j<5; j++) {
            printf("请第%d位裁判为第%d位选手打分：",j+1,i+1);
            scanf("%d",&grades[i][j]);
        }
    }
    //筛选成绩
    for (i=0; i<5; i++) {
        delete(grades[i]);
    }
    //计算最终得分
    double avrage[5];
    for (i=0; i<5; i++) {
        avrage[i] = (grades[i][1]+grades[i][2]+grades[i][3]+grades[i][4]+grades[i][0])/3.0;
    }
    //输出
    int k;
    for (k=0; k<5; k++) {
        double max=avrage[0];
        int index=0;
        for (i=0; i<5; i++) {
            if(avrage[i]>max){
                max=avrage[i];
                index=i;
            }
        }
        avrage[index]=0;
        printf("排名第%d的选手分数为%.2f\n",k+1,max);
    }
    return 0;
}
void delete(int* grades){
    int low=0,high=0;
    int big=grades[0],small=grades[0];
    int i;
    for (i=0; i<5; i++) {
        if(grades[i]>big){
            big=grades[i];
            high=i;
        }
        if(grades[i]<small){
            small=grades[i];
            low=i;
        }
    }
    grades[low]=0;
    grades[high]=0;
}
