//
//  FindByName.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "FindByName.h"
#include "EnterInfo.h"
#include "SumRank.h"
#include <string.h>
void findByName(int num,int students,char n[12],Stu* stu){
    quick_sort(stu, 0, students-1);
    int i;
    for (i=0; i<students; i++) {
        if(strcmp(n, stu[i].name)==0){
            printf("该学生排名为%d\n",i+1);
            int j;
            printf("该学生各科成绩为：\n");
            for (j=0; j<num; j++) {
                printf("课程%d成绩为%.2f\n",j+1,stu[i].grades[j]);
            }
        }
    }
}

