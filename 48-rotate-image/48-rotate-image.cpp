class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        int n = M.size(), depth = n / 2;
        for (int i = 0; i < depth; i++) {
            int len = n - 2 * i - 1, opp = n - 1 - i;
            for (int j = 0; j < len; j++) {
                int temp = M[i][i+j];
                M[i][i+j] = M[opp-j][i];
                M[opp-j][i] = M[opp][opp-j];
                M[opp][opp-j] = M[i+j][opp];
                M[i+j][opp] = temp;
            }
        }
    }
};