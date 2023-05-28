class Solution:
    def minCost(self, n, cuts):
        cuts.append(0)
        cuts.append(n)
        cuts.sort()
        m = len(cuts)
        dp = [[0] * m for _ in range(m)]

        for l in range(2, m):
            for i in range(m - l):
                j = i + l
                dp[i][j] = float('inf')
                for k in range(i + 1, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i])

        return dp[0][m - 1]