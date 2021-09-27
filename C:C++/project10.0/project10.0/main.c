//
//  main.c
//  project10.0
//
//  Created by EthanLeslie on 2021/9/22.
//

#include <stdio.h>
#include "Header.h"
void Push(Pstack stack,int data);
int Pop(Pstack stack);
int main(int argc, const char * argv[]) {
    // insert code here...
    Pstack stack = NULL;
    STACK s;
    s.top=0;
    stack=&s;
    char list[100];
    printf("请输入逆波兰表达式：\n");
    scanf("%s",list);
    int i;
    for (i=0; list[i]!='\0'; i++) {
        if(48<=list[i]&&list[i]<=57){
            Push(stack, list[i]-48);
        }else{
            int num1=Pop(stack);
            int num2=Pop(stack);
            int result=0;
            switch (list[i]) {
                case 43:
                    result=num1+num2;
                    break;
                case 45:
                    result=num2-num1;
                    break;
                case 42:
                    result=num1*num2;
                    break;
                case 47:
                    result=num2/num1;
                    break;
            }
            Push(stack, result);
        }
    }
    int ret=Pop(stack);
    printf("结果为：%d\n",ret);
    return 0;
}
void Push(Pstack stack,int data){
    stack->data[stack->top]=data;
    stack->top++;
}
int Pop(Pstack stack){
    stack->top--;
    return stack->data[stack->top];
}
