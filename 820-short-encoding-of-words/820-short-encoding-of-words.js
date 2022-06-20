var minimumLengthEncoding = function(W) {
    let set = new Set(W)
    for (let word of W)
        if (set.has(word))
            for (let i = 1; i < word.length; i++) 
                set.delete(word.slice(i))
    return Array.from(set).join().length + 1
};