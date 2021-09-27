//
//  GradesLevel.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include "GradesLevel.h"
#include "EnterInfo.h"

void gradesLevel(int num,int students,Stu* stu){
    int i,j;
    int a=0,b=0,c=0,d=0,e=0;
    for (i=0; i<num; i++) {
        for (j=0; j<students; j++) {
            if(stu[j].grades[i]>=90)
                a++;
            else if (stu[j].grades[i]>=80&&stu[j].grades[i]<90)
                b++;
            else if (stu[j].grades[i]>=70&&stu[j].grades[i]<80)
                c++;
            else if(stu[j].grades[i]>=60&&stu[j].grades[i]<70)
                d++;
            else
                e++;
        }
        printf("课程%d五个等级由高到低所占比例为:%fpercents\n%fpercents\n%fpercents\n%fpercents\n%fpercents\n"
               ,i+1,a*100.0/students,b*100.0/students,c*100.0/students,d*100.0/students,e*100.0/students);
    }
}
