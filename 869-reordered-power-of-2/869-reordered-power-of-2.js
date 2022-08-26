var reorderedPowerOf2 = function(N) {
    let res = N.toString().split("").sort().join("")
    for (let i = 0; i < 30; i++)
        if ((1 << i).toString().split("").sort().join("") === res) return true
    return false
};