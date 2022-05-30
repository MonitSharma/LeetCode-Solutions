var divide = function(A, B) {
    if (A === -2147483648 && B === -1) return 2147483647
    let ans = 0, sign = 1
    if (A < 0) A = -A, sign = -sign
    if (B < 0) B = -B, sign = -sign
    if (A === B) return sign
    for (let i = 0, val = B; A >= B; i = 0, val = B) {
        while (val > 0 && val <= A) val = B << ++i
        A -= B << i - 1, ans += 1 << i - 1
    }
    return sign < 0 ? -ans : ans
};
