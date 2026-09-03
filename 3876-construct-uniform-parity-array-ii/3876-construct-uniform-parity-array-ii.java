class Solution {
    public boolean uniformArray(int[] nums1) {
        int min = nums1[0];

        // Find the minimum element
        for (int num : nums1) {
            min = Math.min(min, num);
        }

        // If minimum is odd, always possible
        if (min % 2 != 0) {
            return true;
        }

        // Minimum is even, so every element must be even
        for (int num : nums1) {
            if (num % 2 != 0) {
                return false;
            }
        }

        return true;
    }
}