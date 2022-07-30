var wordSubsets = function(A, B) {
    let Bfreq = new Int8Array(26), cmax = 0,
        check = new Int8Array(26), ans = []
    for (let i = 0; i < B.length; i++, check.fill()) {
        let word = B[i]
        for (let j = 0; j < word.length; j++)
            check[word.charCodeAt(j) - 97]++
        for (let j = 0; j < 26; j++) {
            let diff = check[j] - Bfreq[j]
            if (diff > 0) cmax += diff, Bfreq[j] += diff
            if (cmax > 10) return []
        }
    }
    for (let i = 0; i < A.length; i++, check.fill()) {
        let word = A[i], j
        if (word.length < cmax) continue
        for (j = 0; j < word.length; j++)
            check[word.charCodeAt(j) - 97]++
        for (j = 0; j < 26; j++)
            if (check[j] < Bfreq[j]) break
        if (j === 26) ans.push(word)
    }
    return ans
};