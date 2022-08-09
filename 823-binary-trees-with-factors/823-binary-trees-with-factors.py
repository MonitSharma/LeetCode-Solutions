class Solution:
    def numFactoredBinaryTrees(self, A: List[int]) -> int:
        A.sort()
        fmap, ans = defaultdict(), 0
        for num in A:
            ways, lim = 1, sqrt(num)
            for fA in A:
                if fA > lim: break
                fB = num / fA
                if fB in fmap:
                    ways += fmap[fA] * fmap[fB] * (1 if fA == fB else 2)
            fmap[num], ans = ways, (ans + ways)
        return ans % 1000000007