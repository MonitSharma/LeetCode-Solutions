class NumMatrix {
    constructor(M) {
        let ylen = M.length + 1, xlen = M[0].length + 1
        this.dp = Array.from({length: ylen}, () => new Array(xlen).fill(0))
        for (let i = 1; i < ylen; i++)
            for (let j = 1; j < xlen; j++)
                this.dp[i][j] = M[i-1][j-1] + this.dp[i-1][j] + this.dp[i][j-1] - this.dp[i-1][j-1]
    }

    sumRegion(R1, C1, R2, C2) {
        return this.dp[R2+1][C2+1] - this.dp[R2+1][C1] - this.dp[R1][C2+1] + this.dp[R1][C1]
    }
};
