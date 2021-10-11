//
//  main.c
//  project1
//
//  Created by EthanLeslie on 2021/9/15.
//

#include <stdio.h>
void func(int n,int m,int month,int* num);//n为成兔，m为小兔
int main(int argc, const char * argv[]) {
    int* num;
    int num1=0;
    num = &num1;
    func(1, 0,2,num);
    printf("一年后共有%d只兔子",num1);
    return 0;
}
void func(int n,int m,int month,int*num){
    *num = n+m+n;
    if(month == 12)  return;
    else    func(n+m,n,month+1,num);
}
