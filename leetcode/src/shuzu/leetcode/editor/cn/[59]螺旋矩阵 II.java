package shuzu.leetcode.editor.cn;

//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
// Related Topics 数组 矩阵 模拟 
// 👍 450 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[][] generateMatrix(int n) {
        int squ = n * n;
        int[][] ans = new int[n][n];
        int num = 1;

        int flag = 1;//1-->right,2-->down,3-->left,4-->up
        int bound1 = n-1;
        int bound2 = n-1;
        int bound3 = 0;
        int bound4 = 1;
        ans[0][0] = num++;
        int x = 0,y = 0;
        int first = 1;
        while (true) {
            if (flag == 1) {
                if (y >= bound1&& first == 0) break;
                first = 0;
                for (int i = y + 1; i <= bound1; i++)
                    ans[x][i] = num++;
                y = bound1;
                bound1--;
                flag = 2;
            } else if (flag == 2) {
                if (x >= bound2) break;
                for (int i = x + 1; i <= bound2; i++)
                    ans[i][y] = num++;
                x = bound2;
                bound2--;
                flag = 3;
            } else if (flag == 3) {
                if (y <= bound3) break;
                for (int i = y - 1; i >= bound3 ; i--)
                    ans[x][i] = num++;
                y = bound3;
                bound3++;
                flag = 4;
            } else {
                if (x <= bound4) break;
                for (int i = x - 1; i >= bound4 ; i--)
                    ans[i][y] = num++;
                x = bound4;
                bound4++;
                flag = 1;
            }
        }
        return ans;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
