package shuzu.leetcode.editor.cn;

//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
// Related Topics 数组 回溯 
// 👍 639 👎 0

import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans  = new ArrayList<>();
        List<Integer> list  = new ArrayList<>();
        backtrack(ans,list,n,k,1,1);
        return ans;
    }
    void backtrack (List<List<Integer>> ans,List<Integer> list,int n,int k,int begin,int turn) {
        if (turn == k+1) {
            ans.add(new ArrayList<>(list));
            return;
        }
        for (int i = begin; i <= n; i++) {
            list.add(i);
            backtrack(ans,list,n,k,i+1,turn + 1);
            list.remove(list.size() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
