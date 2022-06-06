var nextPermutation = function(N) {
    const swap = (i, j) =>
        [N[i],N[j]] = [N[j],N[i]]

    let len = N.length - 1, i
    for (i = len - 1; N[i] >= N[i+1];) i--
    let j = i + 1, k = len
    while (j < k) swap(j++,k--)
    if (i >= 0) {
        for (j = i + 1; N[i] >= N[j];) j++
        swap(i,j)
    }
};
