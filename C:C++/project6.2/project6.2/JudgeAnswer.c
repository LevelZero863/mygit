//
//  JudgeAnswer.c
//  project6.2
//
//  Created by EthanLeslie on 2021/9/16.
//

#include <stdio.h>

#include "JudgeAnswer.h"
void JudgeAnswer(int number1,int number2,char* replay){
    int true = number1*number2;
    printf("The question is %d * %d\n",number1,number2);
    printf("Please enter your answer:");
    int a;
    scanf("%d",&a);
    if (a==true) {
        *replay='Y';
    }else{
        *replay='N';
    }
}
