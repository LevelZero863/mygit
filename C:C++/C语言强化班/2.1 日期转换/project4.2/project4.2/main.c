//
//  main.c
//  project4.2
//
//  Created by EthanLeslie on 2021/9/15.
//

#include <stdio.h>
void Monthday(int year,int day,int*pMonth,int*pday);
int main(int argc, const char * argv[]) {
    int year,day;
    scanf("%d %d",&year,&day);
    int *pMonth,*pday;
    int a,b;
    pMonth=&a;
    pday=&b;
    Monthday(year, day, pMonth, pday);
    printf("%d月%d日",a,b);
    return 0;
}
void Monthday(int year,int day,int*pMonth,int*pday){
    int flag = 0;//0,平年；1，闰年
    if((year%4==0&&year%100!=0)||year%400==0)
        flag = 1;
    int months[13]={0,31,0,31,30,31,30,31,31,30,31,31,30};
    if(flag==1) months[2]=29;
    else months[2] =28;
    int i;
    for (i=1; day>months[i]; i++) {
        day-=months[i];
    }
    *pMonth=i;
    *pday=day;
}
