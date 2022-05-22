class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        p = 0 
        q = 1
        while q < len(nums):
            if nums[q] != nums[p]:
                nums[p+1] = nums[q]
                p += 1
            q += 1
        return p + 1