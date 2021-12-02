package shuzu.leetcode.editor.cn;

//给你一个整数数组 distance 。 
//
// 从 X-Y 平面上的点 (0,0) 开始，先向北移动 distance[0] 米，然后向西移动 distance[1] 米，向南移动 distance[2
//] 米，向东移动 distance[3] 米，持续移动。也就是说，每次移动后你的方位会发生逆时针变化。 
//
// 判断你所经过的路径是否相交。如果相交，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：distance = [2,1,1,2]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：distance = [1,2,3,4]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：distance = [1,1,1,1]
//输出：true 
//
// 
//
// 提示： 
//
// 
// 1 <= distance.length <= 10⁵ 
// 1 <= distance[i] <= 10⁵ 
// 
// Related Topics 几何 数组 数学 👍 110 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean isSelfCrossing(int[] distance) {
        if (distance.length <= 3) return false;
        int x = distance[3] - distance[1], y = distance[0] - distance[2];
        if (x >= 0 && y >= 0) return true;
        int bound0 = 0, bound1 = distance[0], bound2 = distance[1], bound3 = distance[0] - distance[2];
        int curIndex = 3;
        return false;
    }
    public boolean isCrossing (int x,int y,int startIndex,int[] distance,int bound0,int bound1,int bound2,int bound3) {
        for (int i = startIndex; i < distance.length; i++) {
            if (i == startIndex) {
                y += distance[i];
                if (y >= bound1) return true;
            } else if (i == startIndex+1) {
                x -= distance[i];
                if (x <= bound2) return true;
            } else if (i == startIndex+2){
                y -= distance[i]l
                if (y <= bound3) return true;
            } else {
                x += distance[i];
                if (x >= bound0) return true;
            }
        }
        return false;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
