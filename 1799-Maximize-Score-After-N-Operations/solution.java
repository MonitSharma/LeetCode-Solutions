class Solution {
    public int maxScore(int[] nums) {
        int n = nums.length;
        
        
        int[][] gcdMatrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdMatrix[i][j] = gcdMatrix[j][i] = gcd(nums[i], nums[j]);
            }
        }
        
       
        int[] dp = new int[1 << n];
        
        
        for (int state = 1; state < (1 << n); state++) {
            
            int cnt = Integer.bitCount(state);
            
            
            if (cnt % 2 == 1) {
                continue;
            }
            
            
            for (int i = 0; i < n; i++) {
                if ((state & (1 << i)) == 0) {
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    if ((state & (1 << j)) == 0) {
                        continue;
                    }
                    int nextState = state ^ (1 << i) ^ (1 << j);
                    dp[state] = Math.max(dp[state], dp[nextState] + cnt / 2 * gcdMatrix[i][j]);
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }
    
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}