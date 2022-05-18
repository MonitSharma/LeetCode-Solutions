class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
            try:
                for i, num in enumerate(nums):
                    if target == num or target < num:
                        return i
                return i + 1
            except:
                return 0