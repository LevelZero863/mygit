//
//  EnterInfo.h
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#ifndef EnterInfo_h
#define EnterInfo_h

#include <stdio.h>
typedef struct STU{
    char name[12];
    double No;
    double grades[6];
    double totalGrades;
}Stu;

void EnterInfo(int students,int num,Stu* stu);

#endif /* EnterInfo_h */
