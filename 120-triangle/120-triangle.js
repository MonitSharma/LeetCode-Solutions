var minimumTotal = function(T) {
    for (let i = T.length - 2; ~i; i--) 
        for (let j = T[i].length - 1; ~j; j--) 
            T[i][j] += Math.min(T[i+1][j], T[i+1][j+1])
    return T[0][0]
}