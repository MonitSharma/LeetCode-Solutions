class Solution {
    public List<String> generateParenthesis(int N) {
        ans = new ArrayList<>();
        m = 2 * N;
        dfs(0, 0, 0);
        return ans;
    }

    private List<String> ans;
    private int m;

    private void dfs(int pos, int open, int seq) {
        if (pos == m) {
            StringBuilder res = new StringBuilder();
            for (int i = 0; i < m; i++)
                res.append((seq & 1 << i) > 0 ? "(" : ")");
            ans.add(res.toString());
            return;
        }
        if (open > 0) dfs(pos+1, open-1, seq);
        if (m - pos > open) dfs(pos+1, open+1, seq | 1 << pos);
    }
}