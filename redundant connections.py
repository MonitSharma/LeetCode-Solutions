class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        par = [i for i in range(len(edges) + 1)]
        def find(x: int) -> int:
            if x != par[x]: par[x] = find(par[x])
            return par[x]
        def union(x: int, y: int) -> None:
            par[find(y)] = find(x)
        for a,b in edges:
            if find(a) == find(b): return [a,b]
            else: union(a,b)
