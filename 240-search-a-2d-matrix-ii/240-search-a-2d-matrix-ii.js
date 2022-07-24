var searchMatrix = function(M, T) {
    let y = M.length, i = 0, j = M[0].length - 1
    while (i < y && ~j) {
        let cell = M[i][j]
        if (cell === T) return true
        else if (cell > T) j--
        else i++
    }
    return false
};