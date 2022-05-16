#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
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
        
    }
} // namespace l72

int main(){
    vector<int> vec{1,3,4};
    cout<<vec[2];
}