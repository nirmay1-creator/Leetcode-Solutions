import java.util.*;

class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;

        Map<Integer, int[]> map = new HashMap<>();

      
        for (int i = 0; i < n; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], new int[]{i, i});
            } else {
                map.get(nums[i])[1] = i;
            }
        }

        int ans = -1;

        for (int x : map.keySet()) {
            int first = map.get(x)[0];
            int last = map.get(x)[1];

            int left = Math.max(0, first - k + 1);
            int right = Math.min(last, n - k);

            int count = right - left + 1;

            if (count == 1) {
                ans = Math.max(ans, x);
            }
        }

        return ans;
    }
}