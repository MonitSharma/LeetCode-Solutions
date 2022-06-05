class Solution(object):
    def isMatch(self, s, p):
        dp = [[False for i in range(len(p)+1)] for j in range(len(s)+1)]
        dp[0][0] = True
        
        s = "#" + s
        p = "#" + p
        
        for j in range(1, len(dp[0])):
            if p[j] == "*":
                dp[0][j] = dp[0][j-1]
        

        
        for i in range(1, len(dp)):
            for j in range(1, len(dp[0])):
                if s[i] == p[j] or p[j] == "?":
                    dp[i][j] = dp[i-1][j-1]
                elif p[j] == "*":
                    dp[i][j] = (dp[i-1][j-1] or dp[i][j-1] or dp[i-1][j])

        return dp[-1][-1]
