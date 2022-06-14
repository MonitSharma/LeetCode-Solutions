class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n < 1: return False
        ans = log(n, 3)
        return abs(ans - round(ans)) < 1e-10