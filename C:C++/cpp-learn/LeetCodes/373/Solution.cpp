//
//  Solution.cpp
//  373
//
//  Created by EthanLeslie on 2022/1/14.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include "Solution.hpp"
using namespace ::std;
    vector<vector<int>> Solution::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
//        vector<vector<int>> ans;
//        vector<vector<int>> choices;
//        unordered_map<string, bool> hash;
//        choices.push_back(vector<int>({nums1[0],nums2[0],0,0}));
//        string in  = to_string(0)+to_string(0);
//        hash.insert({in,true});
//        for (int i = 0; i<k; i++) {
//            if (choices.size() == 0) break;
//            int index = 0;
//            int sum = choices[0][0] + choices[0][1];
//            for (int j = 1; j<choices.size(); j++) {
//                if(sum>choices[j][0]+choices[j][1]) {
//                    index = j;
//                    sum =choices[j][0]+choices[j][1];
//                }
//            }
//            ans.push_back(vector<int>({choices[index][0],choices[index][1]}));
////            for (auto &p :ans) {
////                cout<<p[0]<<" "<<p[1]<<endl;
////            }
////            cout<<"-----------"<<endl;
//            if (choices[index][2]+1 < nums1.size() && hash.find((to_string(choices[index][2]+1)+to_string(choices[index][3])))==hash.end()){
//                choices.push_back(vector<int>({nums1[choices[index][2]+1],nums2[choices[index][3]],choices[index][2]+1,choices[index][3]}));
//                hash.insert({to_string(choices[index][2]+1)+to_string(choices[index][3]),true});
//            }
//
//            if (choices[index][3]+1 <nums2.size() &&hash.find(to_string(choices[index][2])+to_string(choices[index][3]+1))==hash.end()){
//                choices.push_back(vector<int>({nums1[choices[index][2]],nums2[choices[index][3]+1],choices[index][2],choices[index][3]+1}));
//                hash.insert({to_string(choices[index][2])+to_string(choices[index][3]+1),true});
//
//            }
//            choices.erase(choices.begin()+index);
////            for (auto &p :choices) {
////                cout<<p[0]<<" "<<p[1]<<endl;
////            }
////            cout<<"-----------"<<endl;
//        }
//        return ans;
//    }
        auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
                    return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
                };

                int m = nums1.size();
                int n = nums2.size();
                vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);
                for (int i = 0; i < min(k, m); i++) {
                    pq.emplace(i, 0);
                }
                while (k-- > 0 && !pq.empty()) {
                    auto [x, y] = pq.top();
                    pq.pop();
                    ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
                    if (y + 1 < n) {
                        pq.emplace(x, y + 1);
                    }
                }

                return ans;
            }
