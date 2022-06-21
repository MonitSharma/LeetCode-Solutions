class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        N, dupe = len(nums), 0
        seen, sumN = [0] * (N+1), N * (N+1) // 2
        for num in nums:
            sumN -= num
            if seen[num]: dupe = num
            seen[num] += 1
        return [dupe, sumN + dupe]