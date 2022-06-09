class Solution:
    def jump(self, N: List[int]) -> int:
        Nlen, curr, nxt, ans, i = len(N) - 1, -1, 0, 0, 0
        while nxt < Nlen:
            if i > curr:
                ans += 1
                curr = nxt
            nxt = max(nxt, N[i] + i)
            i += 1
        return ans