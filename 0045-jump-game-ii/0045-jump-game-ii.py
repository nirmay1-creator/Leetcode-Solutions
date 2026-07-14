class Solution(object):
    def jump(self, nums):
        jumps = 0
        currEnd = 0
        farthest = 0

        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])

            if i == currEnd:
                jumps += 1
                currEnd = farthest

        return jumps