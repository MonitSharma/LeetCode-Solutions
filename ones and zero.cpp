class Solution {
public:
    int findMaxForm(vector<string>& S, int M, int N) {
        int dp[101][101]{0};
        for (string str : S) {
            int zeros = 0, ones = 0;
            for (char c : str)
                c == '0' ? zeros++ : ones++;
            for (int i = M; i >= zeros; i--)
                for (int j = N; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
        }
        return dp[M][N];
    }
};