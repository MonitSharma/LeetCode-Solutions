var maxProduct = function(words) {
    words.sort((a,b) => b.length - a.length)
    let best = 0, bitsets = new Uint32Array(words.length)
    for (let i = 0; i < words.length; i++) {
        let word = words[i], wlen = word.length, bitset = 0
        if (wlen * words[0].length < best)
            return best
        for (let j = 0; j < wlen; j++)
            bitset |= 1 << (word.charCodeAt(j) - 97)
        for (let j = 0; j < i; j++)
            if ((bitsets[j] & bitset) === 0)
                best = Math.max(best, wlen * words[j].length)
        bitsets[i] = bitset
    }
    return best
};
