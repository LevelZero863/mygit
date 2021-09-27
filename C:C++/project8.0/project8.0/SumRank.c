//
//  SumRank.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "SumRank.h"
#include "EnterInfo.h"
int partition(Stu stu[], int low, int high){
    int key;
    key = stu[low].totalGrades;
    while(low<high){
        while(low <high && stu[high].totalGrades>= key )
            high--;
        if(low<high)
            stu[low++].totalGrades = stu[high].totalGrades;
        while( low<high && stu[low].totalGrades<=key )
            low++;
        if(low<high)
            stu[high--].totalGrades = stu[low].totalGrades;
    }
    stu[low].totalGrades = key;
    return low;
}
void quick_sort(Stu stu[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(stu, start, end);
        quick_sort(stu,start,pos-1);
        quick_sort(stu,pos+1,end);
    }
    return;
}
void sumRank(int students,Stu* stu){
    quick_sort(stu, 0, students-1);
    printf("名次表如下：\n");
    int i;
    for (i=0; i<students; i++) {
        printf("第%d名为%s，总分为：%.2f\n",i+1,stu[students-i-1].name,stu[students-i-1].totalGrades);
    }
}

