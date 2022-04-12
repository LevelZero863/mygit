//
//  main.cpp
//  Chapter1
//
//  Created by EthanLeslie on 2022/1/6.
//
#ifndef _CHAPTER_1_
#define _CHAPTER_1_
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
/**
 cctype 库的函数：～
 */
using namespace :: std;
void func(vector<string> ss);
void fun(initializer_list<string> lst);//未知数量的形参
istream &read(istream &is);
int main(int argc, const char * argv[]) {
    // insert code here...
//    short i = 8;
//  cout<<(i&(i-1))<<endl;
//    cout<<sizeof(i)<<endl;
//    string ss;
//    read(cin)>>ss;
//    cout<<ss<<"2"<<endl;
//    vector<string> vs{"hello","hello"};
//    if (vs.begin()==(vs.end()-2)) {
//        cout<<"xxx"<<endl;
//    }
//    char a1[] = "lnx";
//    char *p1 = begin(a1);
//    char *p2 = end(a1)-1;
//    cout<<(*p1)<<(*p2)<<endl;
//    string s1 = "hello world",s2="Helloworld";
//    cout<<s1.size()<<endl;
//    cout<<s1.length()<<endl;
//    cout<<s1+'2'<<endl;
//    char e = toupper('a');
//    cout<<e<<endl;
//    for(auto &c : s1)
//        c = 'e';
//    cout<<s1<<endl;
    return 0;
}
void fun(initializer_list<string> lst)
{
    
}
istream &read(istream &is){
    string price;
    is>>price;
    cout<<price<<endl;
    return is;
}
#endif
