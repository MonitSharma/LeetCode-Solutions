class Solution:
    def numSubmatrixSumTarget(self, M: List[List[int]], T: int) -> int:
        xlen, ylen, ans, res = len(M[0]), len(M), 0, defaultdict(int)
        for r in M:
            for j in range(1, xlen):
                r[j] += r[j-1]
        for j in range(xlen):
            for k in range(j, xlen):
                res.clear()
                res[0], csum = 1, 0
                for i in range(ylen):
                    csum += M[i][k] - (M[i][j-1] if j else 0)
                    ans += res[csum - T]
                    res[csum] += 1
        return ans