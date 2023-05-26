class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int[] suffixSums = new int[n + 1];
        suffixSums[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSums[i] = suffixSums[i + 1] + piles[i];
        }

        int[][] dp = new int[n][n + 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSums[i];
                } else {
                    for (int x = 1; x <= 2 * m; x++) {
                        int opponentScore = dp[i + x][Math.max(x, m)];
                        int score = suffixSums[i] - opponentScore;
                        dp[i][m] = Math.max(dp[i][m], score);
                    }
                }
            }
        }

        return dp[0][1];
    }
}