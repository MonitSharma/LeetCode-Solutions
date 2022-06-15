var longestStrChain = function(words) {
    let W = Array.from({length: 17}, _ => new Set())
    for (let i = 0; i < words.length; i++) 
        W[words[i].length].add(words[i])
    let dp = new Map(), best = 1
    for (let i = 16; i; i--) {
        if (!W[i-1].size) continue
        for (let word of W[i]) {
            let wVal = dp.get(word) || 1
            for (let j = 0; j < word.length; j++) {
                let pred = word.slice(0,j) + word.slice(j+1)
                if (W[i-1].has(pred) && wVal >= (dp.get(pred) || 1)) {
                    dp.set(pred, wVal + 1)
                    best = Math.max(best, wVal + 1)
                }
            }
        }
    }
    return best
};