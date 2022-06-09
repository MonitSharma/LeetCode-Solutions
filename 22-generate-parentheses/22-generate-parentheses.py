class Solution:
    def generateParenthesis(self, N: int) -> List[str]:
        ans, m = [], 2 * N

        def dfs(pos: int, opn: int, seq: int) -> None:
            if pos == m:
                res = [0] * m
                for i in range(m):
                    res[i] = "(" if seq & 1 << i else ")"
                ans.append("".join(res))
                return
            if opn: dfs(pos+1, opn-1, seq)
            if m - pos > opn: dfs(pos+1, opn+1, seq | 1 << pos)

        dfs(0, 0, 0)
        return ans