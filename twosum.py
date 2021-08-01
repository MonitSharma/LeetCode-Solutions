# brute force method
#class Solution:
#    def twoSum(self, nums: List[int], target: int) -> List[int]:
#        for i in range(len(nums)):
#            for j in range(i+1, len(nums)):
#                if(nums[i]+nums[j]) == target:
#                    return[i,j]
        
        
        
# better solution
class Solution(object):
    def twoSum(self, nums, target):
        
        dict = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in dict:
                return dict[complement],i
            dict[nums[i]] = i