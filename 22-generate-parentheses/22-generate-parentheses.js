var generateParenthesis = function(N) {
    let ans = [], m = 2 * N

    const dfs = (pos, open, seq) => {
        if (pos === m) {
            let res = new Array(m)
            for (let i = 0; i < m; i++)
                res[i] = seq & 1 << i ? "(" : ")"
            ans.push(res.join(""))
            return
        }
        if (open) dfs(pos+1, open-1, seq)
        if (m - pos > open) dfs(pos+1, open+1, seq | 1 << pos)
    }

    dfs(0, 0, 0)
    return ans
};