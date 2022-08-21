var movesToStamp = function(S, T) {
    if (S === T) return [0]
    let slen = S.length, tlen = T.length - slen + 1,
        ans = [], tdiff = true, sdiff, i, j
    S = S.split(""), T = T.split("")
    while (tdiff)
        for (i = 0, tdiff = false; i < tlen; i++) {
            for (j = 0, sdiff = false; j < slen; j++)
                if (T[i+j] === "*") continue
                else if (T[i+j] !== S[j]) break
                else sdiff = true
            if (j === slen && sdiff) {
                for (j = i, tdiff = true; j < slen + i; j++)
                    T[j] = "*"
                ans.unshift(i)
            }
        }
    for (i = 0; i < T.length; i++) if (T[i] !== "*") return []
    return ans
};