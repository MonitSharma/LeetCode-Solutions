class Solution {
    public int numSubmatrixSumTarget(int[][] M, int T) {
        int xlen = M[0].length, ylen = M.length, ans = 0;
        Map<Integer, Integer> res = new HashMap<>();
        for (int[] r : M)
            for (int j = 1; j < xlen; j++)
                r[j] += r[j-1];
        for (int j = 0; j < xlen; j++)
            for (int k = j; k < xlen; k++) {
                res.clear();
                res.put(0,1);
                int csum = 0;
                for (int i = 0; i < ylen; i++) {
                    csum += M[i][k] - (j > 0 ? M[i][j-1] : 0);
                    ans += res.getOrDefault(csum - T, 0);
                    res.put(csum, res.getOrDefault(csum, 0) + 1);
                }
            }
        return ans;
    }
}