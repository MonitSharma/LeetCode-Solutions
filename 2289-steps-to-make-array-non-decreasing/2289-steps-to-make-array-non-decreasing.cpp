class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<int> dp(size(nums));  // dp[i]: number of rounds for nums[i] to be removed
         vector<int> stk;
        for (int i = 0; i < size(nums); ++i) {
            int curr = 0;
            while (!empty(stk) && nums[stk.back()] <= nums[i]) {
                curr = max(curr, dp[stk.back()]); stk.pop_back();
            }
            if (!empty(stk)) {
                dp[i] = curr + 1;
            }
            stk.emplace_back(i);
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};