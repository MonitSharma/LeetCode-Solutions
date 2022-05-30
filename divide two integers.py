class Solution:
    def divide(self, A: int, B: int) -> int:
        if A == -2147483648 and B == -1: return 2147483647
        ans, sign = 0, 1
        if A < 0: A, sign = -A, -sign
        if B < 0: B, sign = -B, -sign
        if A == B: return sign
        while A >= B:
            b = 0
            while B << b <= A: b += 1
            A -= B << b - 1
            ans += 1 << b - 1
        return -ans if sign < 0 else ans
