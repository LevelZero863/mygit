//
//  MakeNumber.c
//  project6
//
//  Created by EthanLeslie on 2021/9/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "MakeNumber.h"

int MakeNumber(void){
    int number;
    number=rand()%MAX_VALUE+MIN_VALUE;
    return number;
}
