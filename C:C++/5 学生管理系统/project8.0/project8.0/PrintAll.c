//
//  PrintAll.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "PrintAll.h"
#include "EnterInfo.h"

void printAll(int num,int students,Stu* stu){
    int i,j;
    for (i=0; i<students; i++) {
        printf("学号：%f 姓名：%s \n",stu[i].No,stu[i].name);
        printf("各科成绩为：\n");
        for (j=0; j<num; j++) {
            printf("%f ",stu[i].grades[j]);
        }
    }
}
