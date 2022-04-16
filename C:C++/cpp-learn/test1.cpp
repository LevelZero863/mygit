//
// Created by EthanLeslie on 2022/4/16.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class GamePlayer {
private:
    static const int NumTurns = 5;
};
bool isBigger (const int& a,const int& b) {
    return a>b;
}
void testSort() {
    vector<int> arr = {56,4,3,15,16,35,12};
    sort(arr.begin(),arr.end(),[](const int& a,const int& b){
        return a>b;
    });
    for (auto iter = arr.begin();iter != arr.end() ; iter ++) {
        cout<<*iter<<endl;
    }
}
void  testConst() {
    const char* s;//s指向的内容不可以修改
    char* tt;
    char y = 'f';
    tt = &y;
    char* const ss = tt; //ss不可以被修改指向,但是ss指向的内容可以被修改
    *ss = 'e';
    cout<<*ss<<endl;
    cout<<y<<endl;
    cout<<*tt<<endl;
}
int main() {
    testConst();
}