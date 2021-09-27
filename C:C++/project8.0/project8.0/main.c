//
//  main.c
//  project8.0
//
//  Created by EthanLeslie on 2021/9/20.
//

#include <stdio.h>
#include "EnterInfo.h"
#include "Average.h"
#include "SingleStu.h"
#include "SumRank.h"
#include "NoRank.h"
#include "NameRank.h"
#include "FindByNo.h"
#include "FindByName.h"
#include "GradesLevel.h"
#include "PrintAll.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    Stu stu[30];
    double NO = 0.0;
    char n[12];
    int num,students;
    while(1){
        int choose;
        printf("请输入序号（1-10）：(输入其他数字退出系统)\n");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                printf("请输入学生人数：\n");
                scanf("%d",&students);
                printf("请输入课程数目：\n");
                scanf("%d",&num);
                EnterInfo(students,num,stu);//1
                break;
            case 2:
                average(students,num, stu);//2
                break;
            case 3:
                singleStu(students,num,stu);//3
                break;
            case 4:
                sumRank(students,stu);//4
                break;
            case 5:
                NoRank(students,stu);//5
                break;
            case 6:
                nameRank(students, stu);//6
                break;
            case 7:
                printf("请输入学号：");
                scanf("%lf",&NO);
                findByNo(num, students, NO, stu);//7
                break;
            case 8:
                printf("请输入姓名：");
                scanf("%s",n);
                findByName(num, students, n, stu);//8
                break;
            case 9:
                gradesLevel(num, students, stu);//9
                break;
            case 10:
                printAll(num, students, stu);//10
                break;
            default:
                return 0;
        }
    }
    return 0;
}
