//
//  NoRank.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "NoRank.h"
#include "EnterInfo.h"
int partition1(Stu stu[], int low, int high){
    int key;
    key = stu[low].No;
    while(low<high){
        while(low <high && stu[high].No>= key )
            high--;
        if(low<high)
            stu[low++].No = stu[high].No;
        while( low<high && stu[low].No<=key )
            low++;
        if(low<high)
            stu[high--].No = stu[low].No;
    }
    stu[low].No = key;
    return low;
}
void quick_sort1(Stu stu[], int start, int end){
    int pos;
    if (start<end){
        pos = partition1(stu, start, end);
        quick_sort1(stu,start,pos-1);
        quick_sort1(stu,pos+1,end);
    }
    return;
}
void NoRank(int students,Stu* stu){
    quick_sort1(stu, 0, students-1);
    students--;
    printf("按学号从大到小排序为：\n");
    while (students>=0) {
        printf("%.2f %s\n",stu[students].No,stu[students].name);
        students--;
    }
}
