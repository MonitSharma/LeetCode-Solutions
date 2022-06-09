moves = [[1,0],[0,1],[-1,0],[0,-1]]

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        N, i, j, pq, ans = len(grid) - 1, 0, 0, [], grid[0][0]
        while i < N or j < N:
            for a,b in moves:
                ia, jb = i + a, j + b
                if ia < 0 or ia > N or jb < 0 or jb > N or grid[ia][jb] > 2500: continue
                heappush(pq, (grid[ia][jb] << 12) + (ia << 6) + jb)
                grid[ia][jb] = 3000
            nxt = heappop(pq)
            ans = max(ans, nxt >> 12)
            i = (nxt >> 6) & ((1 << 6) - 1)
            j = nxt & ((1 << 6) - 1)
        return ans