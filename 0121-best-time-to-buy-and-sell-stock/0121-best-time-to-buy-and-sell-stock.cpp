class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int profit = 0;

        for (int price : prices) {
            mn = min(mn, price);
            profit = max(profit, price - mn);
        }

        return profit;
    }
};