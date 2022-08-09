var numFactoredBinaryTrees = function(A) {
    A.sort((a,b) => a - b)
    let len = A.length, fmap = new Map(), ans = 0
    for (let i = 0; i < len; i++) {
        let num = A[i], ways = 1, lim = Math.sqrt(num)
        for (let j = 0, fA = A[0]; fA <= lim; fA = A[++j]) {
            let fB = num / fA
            if (fmap.has(fB))
                ways += fmap.get(fA) * fmap.get(fB) * (fA === fB ? 1 : 2)
        }
        fmap.set(num, ways), ans += ways
    }
    return ans % 1000000007
};