class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& M, int T) {
        int xlen = M[0].size(), ylen = M.size(), ans = 0;
        unordered_map<int, int> res;
        for (int i = 0; i < ylen; i++)
            for (int j = 1; j < xlen; j++)
                M[i][j] += M[i][j-1];
        for (int j = 0; j < xlen; j++)
            for (int k = j; k < xlen; k++) {
                res.clear();
                res[0] = 1;
                int csum = 0;
                for (int i = 0; i < ylen; i++) {
                    csum += M[i][k] - (j ? M[i][j-1] : 0);
                    ans += res.find(csum - T) != res.end() ? res[csum - T] : 0;
                    res[csum]++;
                }
            }
        return ans;
    }
};