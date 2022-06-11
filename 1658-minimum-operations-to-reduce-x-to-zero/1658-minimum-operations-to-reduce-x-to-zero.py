from typing import List


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        total = sum(nums)
        remainder = total - x
        n = len(nums)
        largest_subarray_len = -1
        current_sum = 0

        j = 0
        for i in range(n):
            current_sum += nums[i]
            while current_sum > remainder and j <= i:
                current_sum -= nums[j]
                j += 1
            if current_sum == remainder:
                largest_subarray_len = max(largest_subarray_len, i - j + 1)

        if largest_subarray_len == -1:
            return largest_subarray_len

        return n - largest_subarray_len