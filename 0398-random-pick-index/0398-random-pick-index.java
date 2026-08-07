import java.util.Random;

class Solution {

    int[] nums;
    Random rand;

    public Solution(int[] nums) {
        this.nums = nums;
        rand = new Random();
    }

    public int pick(int target) {
        int ans = -1;
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                count++;
                if (rand.nextInt(count) == 0) {
                    ans = i;
                }
            }
        }

        return ans;
    }
}