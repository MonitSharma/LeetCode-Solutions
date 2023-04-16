class Solution {
public:
    int numWays(vector<string>& words, string target) {
        static const int MOD = 1e9 + 7;

        vector<uint64_t> dp(size(target) + 1);  // use uint64_t to avoid overflow
        dp[0] = 1;
        for (int i = 0; i < size(words[0]); ++i) {
            vector<int> count(26);
            for (const auto& w : words) {
                ++count[w[i] - 'a'];
            }
            for (int j = size(target) - 1; j >= 0; --j) {
                dp[j + 1] += dp[j] * count[target[j] - 'a'] % MOD;
            }
        }
        return dp.back() % MOD;
    }
};