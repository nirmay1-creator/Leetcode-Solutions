class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> dq;   // stores indices

        for(int i = 0; i < nums.size(); i++) {

            // Remove elements outside current window
            if(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();


            // Remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();


            // Add current element
            dq.push_back(i);


            // Window formed
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};