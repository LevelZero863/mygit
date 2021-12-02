package shuzu.leetcode.editor.cn;

//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 数组 回溯 
// 👍 759 👎 0

import java.time.temporal.JulianFields;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        backtrack(nums,0,ans,list);
        return ans;
    }
    void backtrack (int[] nums,int start,List<List<Integer>> ans,List<Integer> list) {
        if (start == nums.length ) {
            ans.add(new ArrayList<>(list));
            return ;
        }
        List<Integer> ll = new ArrayList<>();
        ll.add(nums[start]);
        for (int i = start; i < nums.length; i++) {
            if (i == start) {
                list.add(nums[i]);
                backtrack(nums,start+1,ans,list);
                list.remove(list.size() - 1);
                continue;
            }
            if (!ll.contains(nums[i])){
                ll.add(nums[i]);
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
}
//leetcode submit region end(Prohibit modification and deletion)
