class Solution:
    def maxScore(self, nums: List[int]) -> int:
        n = len(nums)
        
       
        gcd_matrix = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                gcd_matrix[i][j] = gcd_matrix[j][i] = gcd(nums[i], nums[j])
        
      
        dp = [0] * (1 << n)
        
        
        for state in range(1, 1 << n):
          
            cnt = bin(state).count('1')
            
           
            if cnt % 2 == 1:
                continue
            
            
            for i in range(n):
                if not (state & (1 << i)):
                    continue
                for j in range(i+1, n):
                    if not (state & (1 << j)):
                        continue
                    nextState = state ^ (1 << i) ^ (1 << j)
                    dp[state] = max(dp[state], dp[nextState] + cnt // 2 * gcd_matrix[i][j])
        
        return dp[(1 << n) - 1]