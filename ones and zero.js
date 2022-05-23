var findMaxForm = function(S, M, N) {
    let dp = Array.from({length:M+1},() => new Uint8Array(N+1))
    for (let i = 0; i < S.length; i++) {
        let str = S[i], zeros = 0, ones = 0
        for (let j = 0; j < str.length; j++)
            str.charAt(j) === "0" ? zeros++ : ones++
        for (let j = M; j >= zeros; j--)
            for (let k = N; k >= ones; k--)
                dp[j][k] = Math.max(dp[j][k], dp[j-zeros][k-ones] + 1)
    }
    return dp[M][N]
};