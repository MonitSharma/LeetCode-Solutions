var hasAllCodes = function(S, K) {
    let len = S.length, count = 1 << K,
        seen = new Uint8Array(count),
        num = parseInt(S.slice(len - K + 1), 2) << 1
    for (let i = len - K; ~i; i--) {
        num = ((S.charAt(i) << K) + num) >> 1
        if (!seen[num]) seen[num] = 1, count--
        if (!count) return true
        if (i < count) return false
    }
};
