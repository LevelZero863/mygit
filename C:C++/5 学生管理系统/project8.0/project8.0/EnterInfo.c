//
//  EnterInfo.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//


#include <stdio.h>
#include "EnterInfo.h"

void EnterInfo(int students,int num,Stu* stu){
    printf("请依次输入学号、姓名、各科成绩：\n");
    int i,j;
    for (i=0; i<students; i++) {
        printf("请输入第%d位学生的学号：\n",i+1);
        scanf("%lf",&stu[i].No);
        printf("请输入第%d位学生的姓名：\n",i+1);
        scanf("%s",stu[i].name);
        printf("请输入第%d位学生的各科成绩：\n",i+1);
        for (j=0; j<num; j++) {
            scanf("%lf",&stu[i].grades[j]);
        }
    }
}
