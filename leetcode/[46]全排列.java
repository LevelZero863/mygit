package shuzu.leetcode.editor.cn;

//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
// Related Topics 数组 回溯 
// 👍 1468 👎 0

import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        backtrack(nums,0,ans,list);
        return ans;
    }
    void backtrack (int[] nums,int start,List<List<Integer>> ans,List<Integer> list) {
        if (start == nums.length) {
            ans.add(new ArrayList<>(list));
            return ;
        }
        for (int i = start; i < nums.length; i++) {
            int temp = nums[start];
            nums[start]  = nums[i];
            nums[i] = temp;
            list.add(nums[start]);
            backtrack(nums,start+1,ans,list);
            list.remove(list.size() - 1);
            nums[i] = nums[start];
            nums[start] = temp;
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
