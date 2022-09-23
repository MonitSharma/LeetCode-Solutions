var concatenatedBinary = function(n) {
    let ans = 1, len = 0b100
    for (let i = 2; i <= n; i++) {
        if (i === len) len <<= 1
        ans = (ans * len + i) % 1000000007
    }
    return ans
};