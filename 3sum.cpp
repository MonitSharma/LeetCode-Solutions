class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {      
        int n = nums.size();
        vector<vector<int>> res;
        
        // we've seen in two sum II problem that sorted array
        // makes it easier to solve the problem
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++) {
            
            // to skip duplicates in the sorted array
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            // We have to solve a+b+c = 0
            // We get the value of 'a' from i
            // Using the two pointer approach that we used in
            // two sum II, we'll try to find 'b' and 'c'
            int start = i + 1, end = n - 1, sum;
            
            while(start < end) {
                sum = nums[i] + nums[start] + nums[end];
                // sum = a + b + c
                
                if(sum > 0) {
                    end--;
                }else if(sum < 0) {
                    start++;
                }else {
                    res.push_back(vector<int>{nums[i], nums[start], nums[end]});
                    
                    // to skip duplicates present in between the start and end pointers
                    start++;
                    while(nums[start] == nums[start - 1] && start < end) {
                        start++;
                    }
                }
            }
        }
        return res;
    }
};
