var numSubmatrixSumTarget = function(M, T) {
    let xlen = M[0].length, ylen = M.length,
        ans = 0, res = new Map()
    for (let i = 0, r = M[0]; i < ylen; r = M[++i]) 
        for (let j = 1; j < xlen; j++)
            r[j] += r[j-1]
    for (let j = 0; j < xlen; j++)
        for (let k = j; k < xlen; k++) {
            res.clear(), res.set(0,1), csum = 0
            for (let i = 0; i < ylen; i++) {
                csum += M[i][k] - (j ? M[i][j-1] : 0)
                ans += (res.get(csum - T) || 0)
                res.set(csum, (res.get(csum) || 0) + 1)
            }
        }
    return ans
};