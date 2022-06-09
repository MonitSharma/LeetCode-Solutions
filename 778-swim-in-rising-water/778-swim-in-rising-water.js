const moves = [[1,0],[0,1],[-1,0],[0,-1]]

var swimInWater = function(grid) {
    let N = grid.length - 1, ans = grid[0][0], i = 0, j = 0, prio = 0

    // custom Min-Heap implementation
    let heap = [,]
    const hpush = val => {
        let i = heap.length, par = i >> 1, temp
        heap.push(val)
        while (heap[par] > heap[i]) {
            temp = heap[par], heap[par] = heap[i], heap[i] = temp
            i = par, par = i >> 1
        }
    }
    const hpop = () => {
        if (heap.length === 1) return null
        let top = heap[1], left, right, temp,
            i = 1, child = heap[3] < heap[2] ? 3 : 2
        if (heap.length > 2) heap[1] = heap.pop()
        else heap.pop()
        while (heap[i] > heap[child]) {
            temp = heap[child], heap[child] = heap[i], heap[i] = temp
            i = child, left = i << 1, right = left + 1
            child = heap[right] < heap[left] ? right : left
        }
        return top
    }

    while (i < N || j < N) {
        for (let [a,b] of moves) {
            let ia = i + a, jb = j + b
            if (ia < 0 || ia > N || jb < 0 || jb > N || grid[ia][jb] > 2500) continue
            hpush((grid[ia][jb] << 12) + (ia << 6) + jb)
            grid[ia][jb] = 3000
        }
        let next = hpop()
        ans = Math.max(ans, next >> 12)
        i = (next >> 6) & ((1 << 6) - 1)
        j = next & ((1 << 6) - 1)
    }
    return ans
};