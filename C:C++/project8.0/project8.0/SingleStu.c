//
//  SingleStu.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "SingleStu.h"
#include "EnterInfo.h"
void singleStu(int students,int num,Stu*stu){
    int i,j;
    for (i=0; i<students; i++) {
        double sum=0,aver=0;
        for (j=0; j<num; j++) {
            sum+=stu[i].grades[j];
        }
        stu[i].totalGrades=sum;
        aver=sum/num;
        printf("第%d位学生总分为%.2f,平均分为%.2f\n",i+1,sum,aver);
    }
}
