package shuzu.leetcode.editor.cn;

//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用一次。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
// Related Topics 数组 回溯 
// 👍 639 👎 0

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        //Arrays.sort(candidates);
        int flag = 0;
        for (int i = 1; i < candidates.length; i++) {
            if (candidates[i] != candidates[i-1]){
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            backtrack(candidates,target,ans,list,0);
        else {
            for (int i = 0; i < candidates.length; i++) {
                if (target - candidates[i] >= 0) {
                    list.add(candidates[i]);
                    target -= candidates[i];
                }
            }
            if (target == 0)
                ans.add(new ArrayList<>(list));
        }

        return ans;
    }
    public void backtrack (int[] candidates, int target, List<List<Integer>> ans, List<Integer> list, int t) {

        if (target == 0) {
            if (!ans.contains(list))
                ans.add(new ArrayList<>(list));
            return;
        }
        if (t >= candidates.length) return;
        for (int i = t; i < candidates.length; i++) {
            if (target - candidates[i] >= 0) {
                if (list.isEmpty() || candidates[i] >= list.get(list.size() - 1) ) {
                    int temp = candidates[i];
                    candidates[i] = candidates[t];
                    candidates[t] = temp;
                    list.add(candidates[t]);
                    //calculate the lower bound
                    int sum = 0;
                    for (int j = t+1; j < candidates.length; j++) {
                        sum += candidates[j];
                    }
                    if (sum >= target - candidates[t]) // check
                        backtrack(candidates,target - candidates[t],ans,list,t+1);
                    candidates[t] = candidates[i];
                    candidates[i] = temp;
                    list.remove(list.size()-1);
                }
            }
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
