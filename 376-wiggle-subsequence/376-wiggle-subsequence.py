class Solution:
    def wiggleMaxLength(self, N: List[int]) -> int:
        lenN, i = len(N), 1
        while i < lenN and N[i] == N[i-1]: i += 1
        if i == lenN: return 1
        up, ans = N[i-1] > N[i], 1
        while i < lenN:
            if (up and N[i] < N[i-1]) or (not up and N[i] > N[i-1]):
                up = not up
                ans += 1
            i += 1
        return ans