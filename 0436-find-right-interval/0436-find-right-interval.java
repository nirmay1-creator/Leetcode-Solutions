class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            arr[i][0] = intervals[i][0];
            arr[i][1] = i;
        }

        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int l = 0, r = n - 1;
            int idx = -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (arr[mid][0] >= end) {
                    idx = arr[mid][1];
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            ans[i] = idx;
        }

        return ans;
    }
}