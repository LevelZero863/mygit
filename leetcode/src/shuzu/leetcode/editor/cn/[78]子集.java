package shuzu.leetcode.editor.cn;

//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// nums 中的所有元素 互不相同 
// 
// Related Topics 位运算 数组 回溯 
// 👍 1263 👎 0

import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        ans.add(new ArrayList<>(list));
        for (int i = 1; i < nums.length + 1; i++) {
            backTrack(ans,list,nums,i,1,0);
        }
        return ans;
    }
    void backTrack (List<List<Integer>> ans, List<Integer> list, int[] nums, int count,int turn,int begin) {
        if (count == turn - 1) {
            ans.add(new ArrayList<>(list));
            return;
        }
        for (int i = begin; i < nums.length; i++) {
            list.add(nums[i]);
            backTrack(ans,list,nums,count,turn + 1,i + 1);
            list.remove(list.size() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
