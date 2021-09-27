//
//  NameRank.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "NameRank.h"
#include "EnterInfo.h"
#include <string.h>
int partition2(Stu stu[], int low, int high){
    char key[12];
    strcpy(key, stu[low].name);
    while(low<high){
        while(low <high && strcmp(stu[high].name, key)>0 )
            high--;
        if(low<high)
            strcpy(stu[low++].name, stu[high].name);
        while( low<high && strcmp(stu[high].name, key)<0 )
            low++;
        if(low<high)
            strcpy(stu[high--].name, stu[low].name);
    }
    strcpy(stu[low].name, key);
    return low;
}
void quick_sort2(Stu stu[], int start, int end){
    int pos;
    if (start<end){
        pos = partition2(stu, start, end);
        quick_sort2(stu,start,pos-1);
        quick_sort2(stu,pos+1,end);
    }
    return;
}
void nameRank(int students,Stu* stu){
    quick_sort2(stu, 0, students-1);
    int i;
    printf("按姓名字典序排列如下：\n");
    for (i=0; i<students; i++) {
        printf("%s\n",stu[i].name);
    }
}
