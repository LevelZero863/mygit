//
//  main.c
//  project4.1
//
//  Created by EthanLeslie on 2021/9/15.
//

#include <stdio.h>
int DayOfYear(int year, int month, int day);
int main(int argc, const char * argv[]) {
    int year,month,day;
    scanf("%d %d %d",&year,&month,&day);
    printf("%d",DayOfYear(year, month, day));
    return 0;
}
int DayOfYear(int year, int month, int day){
    //判断是平年还是闰年
    int months[13]={0,31,0,31,30,31,30,31,31,30,31,31,30};
    if((year%4==0&&year%100!=0)||year%400){//闰年
        months[2]=29;
    }else{
        months[2]=28;
    }
    int days=0;
    int i;
    //前month-1个月的天数
    for(i=1;i<month;i++){
        days+=months[i];
    }
    //第month月的天数
    days+=day;
    return days;
}
