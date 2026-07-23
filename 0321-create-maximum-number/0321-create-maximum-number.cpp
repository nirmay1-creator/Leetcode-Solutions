class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for (int num : nums) {
            while (!st.empty() && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            }
            st.push_back(num);
        }

        st.resize(k);
        return st;
    }

    bool greaterVector(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.size()) return true;
        if (i == a.size()) return false;
        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greaterVector(a, i, b, j))
                ans.push_back(i < a.size() ? a[i++] : b[j++]);
            else
                ans.push_back(j < b.size() ? b[j++] : a[i++]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;

        int start = max(0, k - (int)nums2.size());
        int end = min(k, (int)nums1.size());

        for (int i = start; i <= end; i++) {
            vector<int> part1 = maxSubsequence(nums1, i);
            vector<int> part2 = maxSubsequence(nums2, k - i);

            vector<int> candidate = merge(part1, part2);

            if (ans.empty() || greaterVector(candidate, 0, ans, 0))
                ans = candidate;
        }

        return ans;
    }
};