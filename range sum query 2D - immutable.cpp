class NumMatrix {
    vector<vector<long>> dp;

public:
    NumMatrix(vector<vector<int>>& M) {
        int ylen = M.size() + 1, xlen = M[0].size() + 1;
        dp = vector<vector<long>>(ylen, vector<long>(xlen, 0));
        for (int i = 1; i < ylen; i++)
            for (int j = 1; j < xlen; j++)
                dp[i][j] = M[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    }

    int sumRegion(int R1, int C1, int R2, int C2) {
        return (int)(dp[R2+1][C2+1] - dp[R2+1][C1] - dp[R1][C2+1] + dp[R1][C1]);
    }
};
