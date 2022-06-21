class Solution:
    def findErrorNums(self, nums):
        ans = [0,0]
        for num in nums:
            nums[(num - 1) % 10000] += 10000
        for i in range(len(nums)):
            if nums[i] > 20000: ans[0] = i + 1
            elif nums[i] < 10001: ans[1] = i + 1
        return ans