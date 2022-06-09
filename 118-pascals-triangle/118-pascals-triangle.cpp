class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i+1, 1);
            int mid = i >> 1;
            for (int j = 1; j <= mid; j++) {
                int val = ans[i-1][j-1] + ans[i-1][j];
                row[j] = val;
                row[row.size()-j-1] = val;
            }
            ans[i] = row;
        }
        return ans;
    }
};