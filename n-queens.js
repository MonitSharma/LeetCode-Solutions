var solveNQueens = function(N) {
    let ans = [],
        board = Array.from({length: N}, () => new Array(N).fill('.'))

    const place = (i, vert, ldiag, rdiag) => {
        if (i === N) {
            let res = new Array(N)
            for (let row = 0; row < N; row++)
                res[row] = board[row].join("")
            ans.push(res)
            return
        }
        for (let j = 0; j < N; j++) {
            let vmask = 1 << j, lmask = 1 << (i+j), rmask = 1 << (N-i-1+j)
            if (vert & vmask || ldiag & lmask || rdiag & rmask) continue
            board[i][j] = 'Q'
            place(i+1, vert | vmask, ldiag | lmask, rdiag | rmask)
            board[i][j] = '.'
        }
    }

    place(0,0,0,0)
    return ans
};
