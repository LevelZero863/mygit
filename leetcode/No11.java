public class No11 {
    public int maxArea(int[] height) {
        int l =0,r = height.length-1;
        int max = 0;
        while (l != r) {
            int curMax = Math.min(height[l],height[r])*(r-l);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
            if (curMax > max) {
                max = curMax;
            }
        }
        return max;
    }
}
