//
//  ControlNum.c
//  project6.3
//
//  Created by EthanLeslie on 2021/9/16.
//
#include <stdio.h>
#include "ControlNum.h"
#include "MakeNumber.h"
#include "JudgeAnswer.h"
#include "Comments.h"
int ControlNum(int n){
    int count=0;
    int number1;
    int number2;
    char* replay1;
    char replay2;
    replay1=&replay2;
    int i;
    for (i=0; i<n; i++) {
        number1=MakeNumber();
        number2=MakeNumber();
        JudgeAnswer(number1,number2,replay1);
        if(replay2=='N'){
            Comments(0);
        }else{
            Comments(1);
            count++;
        }
    }
    return count;
}
