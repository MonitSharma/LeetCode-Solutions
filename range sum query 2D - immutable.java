class NumMatrix {
    long[][] dp;

    public NumMatrix(int[][] M) {
        int ylen = M.length + 1, xlen = M[0].length + 1;
        dp = new long[ylen][xlen];
        for (int i = 1; i < ylen; i++)
            for (int j = 1; j < xlen; j++)
                dp[i][j] = M[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    }

    public int sumRegion(int R1, int C1, int R2, int C2) {
        return (int)(dp[R2+1][C2+1] - dp[R2+1][C1] - dp[R1][C2+1] + dp[R1][C1]);
    }
}
