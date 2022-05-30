var findRedundantConnection = function(edges) {
    let par = Array.from({length: edges.length + 1}, (_,i) => i)
    const find = x => x === par[x] ? par[x] : par[x] = find(par[x])
    const union = (x,y) => par[find(y)] = find(x)
    for (let [a,b] of edges)
        if (find(a) === find(b)) return [a,b]
        else union(a,b)
};
