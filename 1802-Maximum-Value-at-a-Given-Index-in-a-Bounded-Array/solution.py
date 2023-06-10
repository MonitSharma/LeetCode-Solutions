class Solution:
    def check(self, a):
        left_offset = max(a - self.index, 0)
        result = (a + left_offset) * (a - left_offset + 1) // 2
        right_offset = max(a - ((self.n - 1) - self.index), 0)
        result += (a + right_offset) * (a - right_offset + 1) // 2
        return result - a

    def maxValue(self, n, index, maxSum):
        self.n = n
        self.index = index

        maxSum -= n
        left, right = 0, maxSum
        while left < right:
            mid = (left + right + 1) // 2
            if self.check(mid) <= maxSum:
                left = mid
            else:
                right = mid - 1
        result = left + 1
        return result