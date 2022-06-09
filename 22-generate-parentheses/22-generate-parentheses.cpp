class Solution {
public:
    vector<string> generateParenthesis(int N) {
        m = 2 * N;
        dfs(0, 0, 0);
        return ans;
    }

private:
    vector<string> ans;
    int m;

    void dfs(int pos, int open, int seq) {
        if (pos == m) {
            string res = "";
            for (int i = 0; i < m; i++)
                res += seq & 1 << i ? "(" : ")";
            ans.push_back(res);
            return;
        }
        if (open) dfs(pos+1, open-1, seq);
        if (m - pos > open) dfs(pos+1, open+1, seq | 1 << pos);
    }
};