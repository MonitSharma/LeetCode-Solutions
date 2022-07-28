var isAnagram = function(S, T) {
    let len = S.length, fMap = new Int16Array(123)
    if (T.length !== len) return false
    for (let i = 0; i < len; i++)
        fMap[S.charCodeAt(i)]++
    for (let i = 0; i < len; i++)
        if (--fMap[T.charCodeAt(i)] < 0) return false
    return true
};