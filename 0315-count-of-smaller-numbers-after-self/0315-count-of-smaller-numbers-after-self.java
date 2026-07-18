class Solution {
    public List<Integer> countSmaller(int[] nums) {
        Integer[] ans = new Integer[nums.length];
        Arrays.fill(ans, 0);

        List<Integer> sorted = new ArrayList<>();

        for (int i = nums.length - 1; i >= 0; i--) {
            int idx = lowerBound(sorted, nums[i]);
            ans[i] = idx;
            sorted.add(idx, nums[i]);
        }

        return Arrays.asList(ans);
    }

    private int lowerBound(List<Integer> list, int target) {
        int left = 0, right = list.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (list.get(mid) < target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
}