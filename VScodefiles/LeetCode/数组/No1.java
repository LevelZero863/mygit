import java.util.HashMap;
import java.util.Map;

/**
 * Time 46
 * Space 17
 */
public class No1 {
    public int[] twoSum(int[] nums, int target) {
        int[] ret = new int[2];
        int[] dup = new int[nums.length];
        for (int i = 0; i < dup.length; i++) {
            dup[i] = nums[i];
        }
        Arrays.sort(nums);
        int i,j;
        for (i=0,j=nums.length-1; i<j; ) {
            if (nums[i]+nums[j] > target) {
                j--;
            } else if (nums[i]+nums[j] < target){
                i++;
            } else {
                break;
            }
        }
        int flag = 0;
        for (int n = 0; n < dup.length; n++) {
            if (dup[n] == nums[i] && flag == 0) {
                ret[0] = n;
                flag = 1;
            } else if (dup[n] == nums[j]) {
                ret[1] = n;
            }
        }
        return ret;
    }
    public int[] twoSum2(int[] nums, int target) {
        Map<Integer,Integer> hashtable = new HashMap<>();
        for ( int i = 0; i < nums.length; i++) {
            if (hashtable.containsKey(target - nums[i])) {
                return new int[]{hashtable.get(target - nums[i]),i};
            }
            hashtable.put(nums[i],i);
        }
        return new int[0];
    }

}
