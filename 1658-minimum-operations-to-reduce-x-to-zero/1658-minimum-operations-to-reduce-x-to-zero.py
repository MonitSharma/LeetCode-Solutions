class Solution(object):
    def minOperations(self, nums, x):
        target = sum(nums) - x
        
        if target == 0:
            return len(nums)
        
        left, right = 0, 0 
        curr, cnt = 0, 0 
        
        while right < len(nums):
            curr = curr + nums[right]
            
            while left < right and curr > target:
                curr = curr - nums[left]
                left = left + 1
            if curr == target:
                cnt = max(cnt, right - left + 1)
            right = right + 1
            
        if cnt == 0:
            return -1 
        else:
            return len(nums) - cnt 