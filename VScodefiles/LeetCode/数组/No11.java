public class No11 {
    public int maxArea(int[] height) {
        int len = height.length;
        int[] f = new int[len];
        //init f[i][i+1]
        for (int i = 0; i < f.length-1; i++) {
            f[i] = Math.min(height[i],height[i+1]);
        }
        //main programing
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < len - i; j++) {
                int s = Math.min(height[j],height[j+i])*i;
                int max = Math.max(f[j], f[j+1]);
                f[j] = Math.max(max, s);
            }
        }
        return f[0];
        
    }
}
