var suggestedProducts = function(P, S) {
    P.sort()
    let ans = [], left = 0, right = P.length - 1
    for (let i = 0; i < S.length; i++) {
        let c = S.charAt(i), res = []
        while (P[left]?.charAt(i) < c) left++
        while (P[right]?.charAt(i) > c) right--
        for (let j = 0; j < 3 && left + j <= right; j++)
            res.push(P[left+j])
        ans.push(res)
    }
    return ans
};