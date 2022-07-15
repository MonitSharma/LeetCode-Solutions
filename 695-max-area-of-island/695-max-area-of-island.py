var maxAreaOfIsland = function(grid) {
    let ans = 0, n = grid.length, m = grid[0].length
    const trav = (i, j) => {
        if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j]) return 0
        grid[i][j] = 0
        return 1 + trav(i-1, j) + trav(i, j-1) + trav(i+1, j) + trav(i, j+1)
    }
    for (let i = 0; i < n; i++) 
        for (let j = 0; j < m; j++)
            if (grid[i][j]) ans = Math.max(ans, trav(i, j))
    return ans
};