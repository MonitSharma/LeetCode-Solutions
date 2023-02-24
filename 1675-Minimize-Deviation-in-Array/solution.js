var minimumDeviation = function(nums) {
    let len = nums.length, min = Infinity,
        heap = new Uint32Array(len+1), hix = 1
    heap[0] = 2e9

    const heapify = val => {
        let i = hix, par = i >> 1, temp
        heap[hix++] = val
        while (heap[par] < heap[i]) {
            temp = heap[par], heap[par] = heap[i], heap[i] = temp
            i = par, par = i >> 1
        }
    }

    const extract = () => {
        let max = heap[1], left, right, temp,
            i = 1, child = heap[3] > heap[2] ? 3 : 2
        heap[1] = heap[--hix], heap[hix] = 0
        while (heap[i] < heap[child]) {
            temp = heap[child], heap[child] = heap[i], heap[i] = temp
            i = child, left = i << 1, right = left + 1
            child = heap[right] > heap[left] ? right : left
        }
        return max
    }

    for (let i = 0, n = nums[0]; i < len; n = nums[++i]) {
        if (n % 2) n *= 2
        if (n < min) min = n
        heapify(n)
    }
    let curr = extract(), ans = curr - min
    while (curr % 2 === 0) {
        curr /= 2
        if (curr < min) min = curr
        heapify(curr)
        curr = extract()
        ans = Math.min(ans, curr - min)
    }
    return ans
};