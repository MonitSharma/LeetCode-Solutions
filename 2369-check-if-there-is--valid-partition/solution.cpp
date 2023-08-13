class Solution {
public:
    bool validPartition(std::vector<int>& nums) {
        int n = nums.size();
        
        // If the array has only one element, then it's not possible to partition it into valid subarrays
        if (n == 1) {
            return false;
        }
        
        // Initialization for the first three values
        bool dp_3 = true, dp_2 = false, dp_1 = (n > 1 && nums[0] == nums[1]);
        
        for (int i = 2; i < n; i++) {
            bool dp = false;
            
            // Check for 2 equal elements
            if (nums[i] == nums[i-1] && dp_2) {
                dp = true;
            }
            // Check for 3 equal elements
            else if (i-2 >= 0 && nums[i] == nums[i-1] && nums[i] == nums[i-2] && dp_3) {
                dp = true;
            }
            // Check for 3 consecutive increasing elements
            else if (i-2 >= 0 && nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1 && dp_3) {
                dp = true;
            }

            // Move the window forward
            dp_3 = dp_2;
            dp_2 = dp_1;
            dp_1 = dp;
        }

        return dp_1;
    }
};