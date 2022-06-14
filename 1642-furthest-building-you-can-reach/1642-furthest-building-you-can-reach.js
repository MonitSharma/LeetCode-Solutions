var furthestBuilding = function(H, B, L) {
    let len = H.length - 1,
        pq = new MinPriorityQueue({priority: x => x})
    for (let i = 0; i < len; i++) {
        let diff = H[i+1] - H[i]
        if (diff > 0) {
            if (L > 0) pq.enqueue(diff), L--
            else if (pq.front() && diff > pq.front().element)
                pq.enqueue(diff), B -= pq.dequeue().element
            else B -= diff
            if (B < 0) return i
        }
    }
    return len
};