class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& P, string S) {
        sort(P.begin(), P.end());
        vector<vector<string>> ans;
        int left = 0, right = P.size() - 1;
        for (int i = 0; i < S.length(); i++) {
            vector<string> res;
            char c = S[i];
            while (left <= right && (P[left].length() == i || P[left][i] < c)) left++;
            while (left <= right && (P[right].length() == i || P[right][i] > c)) right--;
            for (int j = 0; j < 3 && left + j <= right; j++)
                res.push_back(P[left+j]);
            ans.push_back(res);
        }
        return ans;
    }
};