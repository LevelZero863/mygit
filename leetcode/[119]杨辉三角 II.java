package shuzu.leetcode.editor.cn;

//给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。 
//
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。 
//
// 
//
// 
//
// 示例 1: 
//
// 
//输入: rowIndex = 3
//输出: [1,3,3,1]
// 
//
// 示例 2: 
//
// 
//输入: rowIndex = 0
//输出: [1]
// 
//
// 示例 3: 
//
// 
//输入: rowIndex = 1
//输出: [1,1]
// 
//
// 
//
// 提示: 
//
// 
// 0 <= rowIndex <= 33 
// 
//
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？ 
// Related Topics 数组 动态规划 
// 👍 318 👎 0

import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= rowIndex+1; i++) {
            if (i == 1) {
                list.add(1);
                ans.add(new ArrayList<>(list));
            } else if (i == 2) {
                list.add(1);
                list.add(1);
                ans.remove(0);
                ans.add(new ArrayList<>(list));
            } else {
                list.add(1);
                for (int j = 0; j < i-2; j++) {
                    int sum = ans.get(0).get(j) + ans.get(0).get(j+1);
                    list.add(sum);
                }
                list.add(1);
                ans.remove(0);
                ans.add(new ArrayList<>(list));
            }
            list.clear();
        }
        return ans.get(0);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
