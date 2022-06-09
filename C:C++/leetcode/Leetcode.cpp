/**
 * @file Leetcode.cpp
 * @author Ethan 
 * @brief leetcode 刷题集
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
#include<unordered_map>
#include<string.h>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std;

namespace l416{
    class Solution {
    public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.cbegin(),nums.cend(),0);
        if (sum%2) return false;
        int target = sum/2,n=nums.size();
        vector<bool> dp(target+1,false);
        //first element
        dp[0]=true;
        for(int i = 1;i<target+1;++i){
            if (nums[0] == i){
                dp[i] = true; 
                break;
            } 
        }
        for(int i = 1;i<n;++i){
            for(int j = target;nums[i]<=j;--j){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];
    }
}; 
}
/**
 * 空间方面：可以用两行n列的数组存储过程结果，能进一步减少空间占用
 * 时间方面：语法细节方面。check函数的if判断比较费时
*/
namespace l474
{
   class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      vector<vector<int> > dp(m+1,vector<int>(n+1,0));  
      int num0=0,num1=0;
 
      for (int i=0;i<strs.size();++i) {
          check(strs[i],num0,num1);
          for (int j = m;num0<=j;--j){
              for (int k =n;num1<=k;--k){
                dp[j][k] = max(dp[j][k],dp[j-num0][k-num1]+1);
              }
          }
      }
      return dp[m][n];
    }
    void check(const string& s,int& m,int& n) {
        m=0;
        n=0;
        for (int i =0;i<s.size();++i) {
            if (s[i] == '0') ++m;
            else ++n;
        }
    }
};
} // namespace l474
namespace l322
{
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1,-1);
        dp[0]=0;
        int n = coins.size();
        for (int i =1;i*coins[0]<=amount;++i) {
            dp[i*coins[0]] = i;
        }
        for (int i =1;i<n;++i) {
            int coin = coins[i];
           for(int j = coin;j<=amount;++j){
               if(dp[j-coin]!=-1){
                   dp[j] = (dp[j]==-1?dp[j-coin]:min(dp[j],dp[j-coin]+1));
               }
           } 
        }
        return dp[amount];
    }
} // namespace l322
namespace l72
{
    int minDistance(string word1, string word2) {
        int len1 = word1.size(),len2 = word2.size();
        vector<vector<int> > dp(len1,vector(len2+1,0));
        //init line 0
        for (int i =0;i<len2+1;++i) {
            dp[0][i] = i;
        }
        //init row0
        for (int i =0;i<len1+1;++i) {
            dp[i][0] = i;
        }
        for (int i = 1;i<len1+1;++i) {
            for (int j= 1;j<len2+1;++j) {
                // if (word1[i] == word2[j])
                //     dp[i][j] = dp[i-1][j-1];
                // else
                //     dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                dp[i][j]= (word1[i-1] == word2[j-1])?dp[i-1][j-1]:min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
        }
        return dp[len1][len2];
    }
} // namespace l72
namespace contest79
{
    int percentageLetter(string s, char letter) {
        int count=0;
        int len =0;
        for (int i=0;i<len;++i){
            if (s[i]==letter) {
                count++;
            }
        }
        return count;
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        size_t len = capacity.size();
        vector<size_t> rest(len);
        for(int i =0;i<len;++i) {
            rest[i] = capacity[i]-rocks[i];
        }
        sort(rest.begin(),rest.end());
        int i =0;
        int ans=0;
        while (additionalRocks>0&&i<len) {
            if (rest[i] > additionalRocks) break;
            else{
                additionalRocks-=rest[i++];
                ans++;
            }
        }
        return ans;
    }
    int minimumLines(vector<vector<int>>& stockPrices) {
        int len = stockPrices.size();
        if (len==0||len==1) return 0;
        sort(stockPrices.begin(),stockPrices.end(),[](vector<int>& a,vector<int>& b){   
            return a[0]<b[0];
        });
        
        int ans =1;
        int yy=stockPrices[1][1]-stockPrices[0][1];
        int xx=stockPrices[1][0]-stockPrices[0][0];
        for (int i =2;i<len;++i) {
            int x = stockPrices[i][0]-stockPrices[i-1][0];
            int y = stockPrices[i][1]-stockPrices[i-1][1];
            int divide = y/x;
            int rest = y%x;
            if (divide==yy/xx) {
                if (rest==0&&yy%xx==0) continue;
                if (yy%xx==rest&&xx==x) continue;
            }        
            yy = y;
            xx=x;
            ans++;
        }
        return ans;
    }
    size_t minnsum(vector<int>::const_iterator begin,vector<int>::const_iterator end) {
        vector<size_t> ret(2);
        ret[0] = *begin;
        ret[1] = 0;
        while (begin!=end) {
            if (*begin<ret[0]) {
                ret[0]=*begin;
            }
            ret[1]+=*begin;
            ++begin;
        }
        return ret[0]*(ret[1]%(size_t)(10e9+7));
    }
    int totalStrength(vector<int>& strength) {
       vector<size_t> ans;
       int len = strength.size();
       for (int i=1;i<len+1;++i) {
           for (auto a = strength.cbegin();a!=strength.cend();++a) {
               ans.push_back(minnsum(a,a+1));
           }
       }
        int ret=0;
        for (auto a : ans) {
            ret+=(a%(int)(10e9+7));
        }
        return ret;
    }
    
} // namespace contest79

namespace l650
{
    int minSteps(int n) {
        vector<size_t> dp(n+1);
        int size = sqrt(n);//以n的根号2为界，所有可能结果对称
        for (int i = 2;i<n+1;++i) {
            dp[i] = i;
            for (int j = 2;j<=size;++j)  {//不能以1开始，因为dp[i/j]应该是已知的
                if (i%j==0) {//寻找到第一个因数就停止，因为后面的因数都是通过第一个因素加上去的
                    dp[i] = dp[j]+dp[i/j];
                    break;
                }
            }
        }
        return dp[n];
    }
} // namespace l650
namespace l309
{
    int maxProfit(vector<int>& prices) {
        return 1;
    }
} // namespace l309
namespace contest196
{
    int minMaxGame(vector<int>& nums) {
        int len = nums.size();
        //if (len == 1) return nums[0];
        vector<int> newNums(len/2);
        while (len!=1) {
            for (int i =0;i<len/2;++i) {
                if (i%2==0)
                    newNums[i] = min(nums[2*i],nums[2*i+1]);
                else 
                    newNums[i] = max(nums[2*i],nums[2*i+1]);
            }
            len/=2;
            for (int i =0;i<newNums.size();++i) {
                nums[i] = newNums[i];
            }
        }
        return nums[0];
    }
    int partitionArray(vector<int>& nums, int k) {
        if (nums.size()==1) return 1;
        
        sort(nums.begin(),nums.end());
        if (k==0) {
            int ret=1;
            int front=nums[0];
            for (int i=1;i<nums.size();++i) {
                if (front!=nums[i]) {
                    ret++;
                    front=nums[i];
                }
            }
            return ret;
        }
        int ans=0;
        int left=0,right=nums.size()-1;
        while (left<=right&&nums[right]-nums[left]>k) {
            for (int i = right;i>=left;--i) {
                if (nums[i]-nums[left]<=k) {
                    ans++;
                    left = i+1;
                    break;
                }
            }
        }
        return ans+1;

    }
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mm;
        for (int i=0;i<nums.size();++i) {
            mm[nums[i]] = i;
        }
        for (int i =0;i<operations.size();++i) {
            int index = mm[operations[i][0]];
            nums[index] = operations[i][1];
            mm.erase(operations[0][1]);
            mm.insert({operations[i][1],index});
        }
        return nums;
    }
    class TextEditor {
    public:
        string txt;
        TextEditor() {
            txt = "|";
        }
        
        void addText(string text) {
            int index=0;
            for (int i =0;i<txt.size();++i) {
                if (txt.at(i) == '|') {
                    index = i;
                } 
            }
            for (int i =0;i<text.size();++i) {
                txt.insert(index-text.size(),index,text.at(i));
            }
            
        }
        int deleteText(int k) {
            int index=0;
            for (int i =0;i<txt.size();++i) {
                if (txt.at(i) == '|') {
                    index = i;
                } 
            }
            for (int i=0;i<k;++i) {
                txt.erase(txt.begin()+index-1-i);
            }
            return txt.size()-1;
        }
        
        string cursorLeft(int k) {
            int index=0;
            for (int i =0;i<txt.size();++i) {
                if (txt.at(i) == '|') {
                    index = i;
                } 
            }
            k--;
            int s=0;
            if (index-k>=0) {
                s= index-k;
            } else {
                s=0;
            }
            char c = txt.at(s);
            txt[s] = '|';
            txt[index] = c;
            string ss (txt.begin(),txt.end()-1);
            for(int i =0;i<ss.size();++i) {
                if (ss[i] =='|') {
                    ss.erase(i);
                    break;
                }
            }
            return ss;
        }
        
        string cursorRight(int k) {
            int index=0;
            for (int i =0;i<txt.size();++i) {
                if (txt.at(i) == '|') {
                    index = i;
                } 
            }
            k--;
            int s=0;
            if (index+k<txt.size()) {
                s= index+k;
            } else {
                s=txt.size()-1;
            }
            char c = txt.at(s);
            txt[s] = '|';
            txt[index] = c;
            string ss (txt.begin(),txt.end()-1);
            for(int i =0;i<ss.size();++i) {
                if (ss[i] =='|') {
                    ss.erase(i);
                    break;
                }
            }
            return ss;
        }

};
} // namespace contest196
namespace l448
{
    class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            for (int i = 0;i<nums.size();++i) {
                int temp = nums[i];
                if (temp-1==i||nums[i] == nums[temp-1]) continue;
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
                --i;
            }
            vector<int> ans;
            for (int i =0;i<nums.size();++i) {
                if (nums[i] != i+1) ans.push_back(i+1);
            }
            return ans;
        }
};
} // namespace l448

namespace l769
{
    class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
            int ans =0,target=0,subMax=arr[0];
            for (int i=0;i<arr.size();++i) {
                if (arr[i]>subMax) subMax = arr[i];
                if (arr[i]==target) {
                    ans++;
                    
                    int nextIndex = i+1;
                    int m = subMax;
                    for (int j=nextIndex;j<arr.size();++j) {
                        if (arr[j] > m) m = arr[j];
                        if (arr[j] < subMax) {
                            nextIndex = j+1;
                            subMax = m;
                        }
                    }
                    i = nextIndex-1;
                    target = subMax+1;
                    if (i+1<arr.size()) subMax = arr[i+1];
                }
            }
            return ans;
        }
};
} // namespace l769
namespace l232
{
    class MyQueue {
    public:
        stack<int> st1;
        stack<int> st2;
        MyQueue() {
            
        }
        
        void push(int x) {
            st1.push(x);
        }
        
        int pop() {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int ans = st2.top();
            st2.pop();
            while(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
            return ans;
        }
        
        int peek() {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int ans = st2.top();
            while(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
            return ans;
        }
        
        bool empty() {
            return st1.empty();
        }
};
} // namespace l232

namespace l155
{
    class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};


} // namespace l155
namespace l20
{
    class Solution {
    public:
        bool isValid(string s) {
            if (s.size()==1) return false;
            stack<char> st;
            for (int i=0;i<s.size();++i) {
                if (s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
                else {
                    if (st.empty()) return false;
                    char tp = st.top();
                    if (s[i]==')'&&tp=='(') {
                        st.pop();
                        continue;
                    }
                    if(s[i]==']'&&tp=='['){
                        st.pop();
                        continue;
                    } 
                    if (s[i]=='}'&&tp=='{') {
                        st.pop();
                        continue;
                    }
                   return false;
                }
            }
            if(!st.empty()) return false;
            return true;
        }
};
} // namespace l20
namespace l739
{
    class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            stack<int> st1,st2;
            vector<int> ans(temperatures.size());
            st1.push(temperatures[0]);
            st2.push(0);
            int i = 1;
            while(i<temperatures.size() ) {
                if (st1.empty()) {
                    st1.push(temperatures[i]);
                    st2.push(i);
                    ++i;
                    continue;
                }
                int tp = st1.top();
                if (temperatures[i]<=tp) {
                    st1.push(temperatures[i]);
                    st2.push(i);
                    ++i;
                } else {
                    int index = st2.top();
                    ans[index] = i-index;
                    st1.pop();
                    st2.pop(); 
                }
            }
            while(!st2.empty()) {
                ans[st2.top()] = 0;
                st2.pop();
            }
            return ans;
        }
};
} // namespace l739
namespace l23
{
    struct ListNode{
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.empty()) return nullptr;
            auto cmp = [](const ListNode* l1,const ListNode* l2) {
                return l1->val>l2->val;
            };
            priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
            for (ListNode* ln:lists) {
                while(ln) {
                    pq.push(ln);
                    ln=ln->next;
                }
            }
            ListNode* now = new ListNode(0);
            ListNode* ans = now;
            while(!pq.empty() ) {
                now->next=pq.top();
                now=now->next;
                now->next=NULL;
                pq.pop();
            }
            return ans->next;
        }
};
} // namespace l23
namespace l218
{
    class Solution {
    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            vector<vector<int>> ans;
            priority_queue<pair<int,int>> max_heap;
            int i =0,len=buildings.size();
            int cur_x,cur_h;
            while(i<len||!max_heap.empty()) {
                if (max_heap.empty()||i<len&&buildings[i][0]<=max_heap.top().second) {
                    cur_x = buildings[i][0];
                    while(i<len&&cur_x==buildings[i][0]){
                        max_heap.emplace(buildings[i][2],buildings[i][1]);
                        ++i;
                    }
                } else {
                    cur_x = max_heap.top().second;
                    while(!max_heap.empty()&&cur_x>=max_heap.top().second) {
                        max_heap.pop();
                    }
                }
                cur_h = (max_heap.empty())?0:max_heap.top().first;
                if(ans.empty()||cur_h != ans.back()[1]) {
                    ans.push_back({cur_x,cur_h});
                }
            }
            return ans;
        }
};
} // namespace l218
namespace l241
{
    class Solution {
    public:
        vector<int> diffWaysToCompute(string expression) {
            
            int count =0;
            vector<int> index;
            vector<int> ans;
            for(int i =0;i<expression.size();++i) 
                if (expression.at(i)=='+'||expression.at(i)=='-'||expression.at(i)=='*') {
                    ++count;
                    index.push_back(i);
                }
            if (count==0) {
                ans.push_back(expression[0]-'0');
            }else if (count==1) {
                int c=0;//运算符
                int a=0;
                vector<int> b;
                for (int i=0;i<expression.size();++i) {
                    if (expression.at(i)=='+'||expression.at(i)=='-'||expression.at(i)=='*') {
                        b.push_back(a);
                        a=0;
                        c=i;
                        continue;
                    }
                    a=a*10+(expression.at(i)-'0');
                }
                if (expression.at(c)=='+') ans.push_back(b[0]+a);
                else if(expression.at(c)=='-' ) ans.push_back(b[0]-a);
                else ans.push_back(b[0]*a);
            }else {
                for(int i =0 ;i<count;++i) {
                    vector<int> l,r;
                    l=diffWaysToCompute(expression.substr(0,index[i]));
                    r=diffWaysToCompute(expression.substr(index[i]+1,expression.size()-index[i]));
                    for (int j=0;j<l.size();++j) {
                        for (int k=0;k<r.size();++k) {
                            if (expression.at(index[i])=='+') ans.push_back(l[j]+r[k]);
                            else if (expression.at(index[i])=='-') ans.push_back(l[j]-r[k]);
                            else ans.push_back(l[j]*r[k]);
                        }
                    }
                }
            }
            return ans;
        }
    };
} // namespace l241
namespace l932
{
    class Solution {
    public:
        vector<int> beautifulArray(int n) {
            vector<int> ans;
            if (n==1) {
                ans = {1};
                return ans;
            } 
            if (n==2) {
                ans = {1,2};
                return ans;
            }
            int left;
            if (n%2==0) left=n/2;
            else left = n/2+1;
            vector<int> ansLeft = beautifulArray(left);
            vector<int> ansRight = beautifulArray(n/2);
            
            for (int a:ansLeft) {
                ans.push_back(a*2-1);
            }
            for (int a:ansRight) {
                ans.push_back(a*2);
            }
            return ans;
        }
};
} // namespace l932
namespace l504
{
    class Solution {
    public:
        string convertToBase7(int num) {
            stack<int> st;
            string ans;
            if (num<0) {
                num = -num;
                ans.append("-");
            }
            while(num>=7) {
                st.push(num%7);
                num/=7;
            }
            
            while(!st.empty()) {
                ans.append(to_string(st.top()));
                st.pop();
            }
            return ans;
        }
};
} // namespace l504
namespace l172
{
    class Solution {
    public:
        int trailingZeroes(int n) {
            vector<int> result{1};
            for (int i=2;i<=n;++i) {
                
            }
        }
        vector<int>& func(vector<int> &ve,int n) {
            vector<int> cc(ve);            
            int len = ve.size();
            int temp=0;
            int num =0;
            for(int i=len-1;i>=0;--i) {
                num = temp+cc[i]*n;
                cc[i] = num%10;
                temp = num/10; 
            }
            if (num>=10) cc.insert(cc.begin(),temp);
            return cc;
        }
};
} // namespace l172

int main(){
  
}