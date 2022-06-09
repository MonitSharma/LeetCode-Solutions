var findPaths = function(m, n, maxMove, startRow, startColumn) {
    if (!maxMove) return 0
    let dpCurr = Array.from({length: m+2}, () => new Uint32Array(n+2)),
        dpLast = Array.from({length: m+2}, () => new Uint32Array(n+2))
    for (let i = 1; i <= m; i++)
        dpCurr[i][1]++, dpCurr[i][n]++
    for (let j = 1; j <= n; j++)
        dpCurr[1][j]++, dpCurr[m][j]++
    let ans = dpCurr[startRow+1][startColumn+1]
    for (let d = 1; d < maxMove; d++) {
        [dpCurr, dpLast] = [dpLast, dpCurr]
        for (let i = 1; i <= m; i++)
            for (let j = 1; j <= n; j++)
                dpCurr[i][j] = (dpLast[i-1][j] + dpLast[i+1][j] + dpLast[i][j-1] + dpLast[i][j+1]) % 1000000007
        ans = (ans + dpCurr[startRow+1][startColumn+1]) % 1000000007
    }
    return ans
};