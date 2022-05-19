class Solution:
    def longestIncreasingPath(self, M: List[List[int]]) -> int:
        ylen, xlen = len(M), len(M[0])
        @lru_cache(maxsize=None)
        def dfs(y, x):
            val = M[y][x]
            return 1 + max(
                dfs(y+1,x) if y < ylen - 1 and val > M[y+1][x] else 0,
                dfs(y-1,x) if y > 0 and val > M[y-1][x] else 0, 
                dfs(y,x+1) if x < xlen - 1 and val > M[y][x+1] else 0,
                dfs(y,x-1) if x > 0 and val > M[y][x-1] else 0)
        return max(dfs(y, x) for y in range(ylen) for x in range(xlen))