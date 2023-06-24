class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    const int n = rods.size();
    const int sum = accumulate(rods.begin(), rods.end(), 0);
    
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      const int h = rods[i - 1];
      for (int j = 0; j <= sum - h; ++j) {
        if (dp[i - 1][j] < 0)
          continue;
        // don't use rods[i - 1]
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        // Put on the taller pile
        dp[i][j + h] = max(dp[i][j + h], dp[i - 1][j]);
        // Put on the shorter pile
        dp[i][abs(j - h)] = max(dp[i][abs(j - h)], dp[i - 1][j] + min(j, h));
      }
    }

    return dp[n][0];
  }
};