class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++)
            arr[i + 1] = nums[i];

        n += 2;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 1; len <= n - 2; len++) {
            for (int left = 1; left + len - 1 <= n - 2; left++) {
                int right = left + len - 1;

                for (int k = left; k <= right; k++) {
                    dp[left][right] = max(
                        dp[left][right],
                        dp[left][k - 1] +
                        dp[k + 1][right] +
                        arr[left - 1] * arr[k] * arr[right + 1]
                    );
                }
            }
        }

        return dp[1][n - 2];
    }
};