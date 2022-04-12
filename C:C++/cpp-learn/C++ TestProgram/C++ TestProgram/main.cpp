//
//  main.cpp
//  C++ TestProgram
//
//  Created by EthanLeslie on 2022/3/15.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;
class book {
private:
    string name;
    string no;
public:
    book(string a,string b){
        name = a;
        no = b;
    }
    string getName () {
        return name;
    }
    string getNo(){
        return no;
    }
    
};
int main(int argc, const char * argv[]) {
//    list<string> slist;
//    slist.insert(slist.begin(),3, "hello");
//    vector<string> v = {"world","let","think"};
//    slist.insert(slist.begin(), v.end()-2,v.end());
//
//    for(auto str : slist) {
//        cout<<str<<endl;
//    }
//    vector<book> b;
//    b.emplace(b.begin(),"think","111");
//
//    for(auto book : b) {
//        cout<<book.getName()<<endl;
//        cout<<book.getNo()<<endl;
//    }
    vector<string> str = {"ab","cd","ef","ab","ef","gh","gh"};
    sort(str.begin(),str.end());
    auto str_end = unique(str.begin(), str.end());
    str.erase(str_end, str.end());
    for(auto s : str) {
        cout<<s<<endl;
    }
    
}
