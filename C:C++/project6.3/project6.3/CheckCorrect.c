//
//  CheckCorrect.c
//  project6.3
//
//  Created by EthanLeslie on 2021/9/16.
//

#include "CheckCorrect.h"
#include <stdio.h>

int CheckCorrect(int count){
    if(count>7){
        printf("*************The rate of correction is more than 75 percent ***********\n");
        return 0;
    }else{
        printf("T*************he rate of correction is lower than 75 percent ***********\n");
        return 1;
    }
}
