class Solution {
public:
    int minimumTotal(vector<vector<int>>& T) {
        for (int i = T.size() - 2; ~i; i--) 
            for (int j = T[i].size() - 1; ~j; j--) 
                T[i][j] += min(T[i+1][j], T[i+1][j+1]);
        return T[0][0];
    }
};