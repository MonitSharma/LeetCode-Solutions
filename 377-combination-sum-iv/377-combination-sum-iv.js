var combinationSum4 = function(N, T) {
    let dp = new Uint32Array(T+1)
    dp[0] = 1
    for (let i = 1; i <= T; i++)
        for (let num of N)
            if (num <= i) dp[i] += dp[i-num]
    return dp[T]
};