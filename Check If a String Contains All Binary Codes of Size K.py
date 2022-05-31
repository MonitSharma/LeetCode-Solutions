class Solution:
    def hasAllCodes(self, S: str, K: int) -> bool:
        count = 1 << K
        seen = set()
        for i in range(len(S) - K, -1, -1):
            num = S[i:i+K]
            if num not in seen:
                seen.add(num)
                count -= 1
            if not count: return True
            if i < count: return False
