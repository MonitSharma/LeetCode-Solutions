class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        nmap, total, best, left = [0] * 10001, 0, 0, 0
        for right in nums:
            nmap[right] += 1
            total += right
            while nmap[right] > 1:
                nmap[nums[left]] -= 1
                total -= nums[left]
                left += 1
            best = max(best, total)
        return best