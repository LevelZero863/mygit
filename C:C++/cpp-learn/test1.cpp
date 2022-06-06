//
// Created by EthanLeslie on 2022/4/16.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iterator>
using namespace std;
//测试类1
class GamePlayer {
private:
    static const int NumTurns = 5;
    mutable int user;
    int scores[NumTurns];
public:
    inline GamePlayer& operator= (GamePlayer& gamePlayer){
        return gamePlayer;
    }
    inline void setUser(int id) const{
        user = id;
    }
    inline const int& getUser() const{
        return user;
    }
    inline const int* getNumTurns () const{
        return &NumTurns;
    }

};
const int GamePlayer::NumTurns; // 取class的专属常量（且为整数类型）地址，需要添加定义式
//测试类2
class NameObject{
private:
    string& nameValue;
    int age;
public:
    static const int u = 9;
   NameObject(string& name,int age):
        nameValue(name),
        age(age)
        {}
   string& getNameValue() {
       return nameValue;
   }
   void setNameValue(string& name){
       nameValue=name;
   }
protected:
    static const int num = 4;
};

bool isBigger (const int& a,const int& b) {
    return a>b;
}
void testSort() {
    vector<int> arr{1,3};
    sort(arr.begin(),arr.end(),[](const int& a,const int& b){
        return a>b;
    });
    for (auto iter = arr.begin();iter != arr.end() ; iter ++) {
        cout<<*iter<<endl;
    }
}
/*
 * const出现在*左边意味着被指物是常量，出现在右边意味着指针本身是常量
 */
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
void testVector() {

//    vector<vector<int>> vec(10,vector<int>(10,0));
//    vec[2][0] = 1;
//    vector<int> t{1,2,4};
//    cout<<vec[2][0]<<endl;
//    cout<<vec[0][0]<<endl;
      vector<int> ve{1,2};
      ve[15] = 2;
      cout<<ve[14];
}

void testEfficiency () {
    auto start=clock();

    GamePlayer gamePlayer;
    cout<<gamePlayer.getNumTurns();

    auto end = clock();
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<(double)(end-start)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
}
void testConstClass () {
    const GamePlayer gamePlayer{};
    gamePlayer.setUser(5);
    cout<<gamePlayer.getUser()<<endl;
}
void testSqrt() {
    int a =16;
    int b =12;
    cout<<sqrt(a)<<endl;
    cout<<sqrt(b)<<endl;
}
void testReference() {
    string s("great");
    string p("worst");
    string& ss = s;
    string& pp =p;

    pp=ss;
    cout<<pp<<endl;
    string newDog("persephone");
    string oldDog("satch");
    NameObject dog1(newDog,4);
    NameObject dog2(oldDog,14);
    dog1.setNameValue(dog2.getNameValue());
    cout<<dog1.getNameValue()<<endl;
}
void testEndian(){
    int number = 1;
    if(*(char *)&number)
        cout<<"little-endian"<<endl;
    else
        cout<<"big-endian"<<endl;
}
bool compareMap(const size_t & a,const size_t& b) {
    return a>b;
}
void testMap(){
    // map<string,size_t> word_count;
    // string word;
    // int count=5;
    // for (const auto& w: word_count) 
    //     cout<<w.first<<"occurs"<<w.second
    //         <<((w.second>1)?"times":"time")<<endl;
    multimap<size_t,size_t> mp;
    mp = {{2,4},{1,7},{1,3},{6,5},{4,2},{4,9},{4,3},{4,10},{2,6},{2,2}};
    
    const auto [lb,ub] = mp.equal_range(1);
    auto dis = distance(lb,ub);
    cout<<dis;
}

bool comparePair(const pair<size_t,size_t>& p1,const pair<size_t,size_t>& p2) {
    if (p1.first!=p2.first) {
        return p1.first<p2.first;
    }else {
        return p1.second<p2.second;
    }
}
bool compareInt(const size_t a,const size_t b) {
    return a>b;
}
void testSet(){
    // set<pair<int,int>> visited;
    // visited.insert(make_pair(3,5));
    // if (visited.find({3,5})!=visited.end()) {
    //     cout<<"{3,5} is found"<<endl;
    // } 
    // if (visited.find({3,1})!=visited.end()) {
    //     cout<<"{3,1} is found"<<endl;
    // }
    multiset<pair<size_t,size_t>,decltype(comparePair)*> mset(comparePair);
    vector<pair<size_t,size_t>> vec;
    vec = {{2,4},{1,7},{1,3},{6,5},{4,2},{4,9},{4,3},{4,10},{2,6},{2,2}};
    //mset.insert(vec.cbegin(),vec.cend());//correct
    mset = {{2,4},{1,7},{1,3},{6,5},{4,2},{4,9},{4,3},{4,10},{2,6},{2,2}};//correct
    //multiset<pair<size_t,size_t>,decltype(comparePair)*> mset(vec.cbegin(),vec.cend(),comparePair);//correct
    
    const auto [lb,ub] = mset.equal_range(make_pair(2,4));
    cout << distance(lb,ub);
    
    // for (auto m:mset) {
    //     cout<<m.first<<" "<<m.second<<endl; 
    // }

}
int main() {
    testMap();
}   