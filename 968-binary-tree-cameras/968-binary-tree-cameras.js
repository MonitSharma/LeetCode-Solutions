var minCameraCover = function(root) {
    let ans = 0
    const dfs = node => {
        if (!node) return 0
        let val = dfs(node.left) + dfs(node.right)
        if (val === 0) return 3
        if (val < 3) return 0
        ans++
        return 1
    }
    return dfs(root) > 2 ? ans + 1 : ans    
};