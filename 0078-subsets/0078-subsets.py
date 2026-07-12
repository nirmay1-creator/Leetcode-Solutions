class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        subset = []
        
        def backtrack(i):
            # Base case: if we've made a decision for all elements
            if i >= len(nums):
                res.append(list(subset))
                return
            
            # Decision to include nums[i]
            subset.append(nums[i])
            backtrack(i + 1)
            
            # Decision NOT to include nums[i] (Backtrack)
            subset.pop()
            backtrack(i + 1)
            
        backtrack(0)
        return res