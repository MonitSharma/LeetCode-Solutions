var maximumUnits = function(B, T) {
    B.sort((a,b) => b[1] - a[1])
    let ans = 0
    for (let i = 0; T && i < B.length; i++) {
        let count = Math.min(B[i][0], T)
        ans += count * B[i][1], T -= count
    }
    return ans
};