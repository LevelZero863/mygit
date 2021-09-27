//
//  FindByNo.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "FindByNo.h"
#include "EnterInfo.h"
#include "SumRank.h"

void findByNo(int num,int students,double NO,Stu* stu){
    quick_sort(stu, 0, students-1);
    int i;
    for (i=0; i<students; i++) {
        if((int)stu[i].No==(int)NO){
            printf("该学生排名为%d\n",students-i);
            int j;
            printf("该学生各科成绩为：\n");
            for (j=0; j<num; j++) {
                printf("课程%d成绩为%.2f\n",j+1,stu[students-i-1].grades[j]);
            }
        }
    }
}
