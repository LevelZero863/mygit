//
//  Average.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "Average.h"
#include "EnterInfo.h"
void average(int students,int num,Stu* stu){
    int i,j;
    for (i=0; i<num; i++) {
        double sum=0;
        for (j=0; j<students; j++) {
            sum+=stu[j].grades[i];
        }
        double aver = (double)(sum/students);
        printf("第%d门课程平均分是%.2f\n",i+1,aver);
    }
}
