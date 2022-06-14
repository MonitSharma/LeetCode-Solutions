var leastBricks = function(wall) {
    let freq = new Map(), best = 0
    for (let i = 0; i < wall.length; i++) {
        let row = wall[i], rowSum = row[0]
        for (let j = 1; j < row.length; j++) {
            freq.set(rowSum, (freq.get(rowSum) || 0) + 1)
            rowSum += row[j]
        } 
    }
    for (let [k,v] of freq)
        if (v > best) best = v
    return wall.length - best
};