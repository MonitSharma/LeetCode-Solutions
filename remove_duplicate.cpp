class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int last = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[last]) {
                ++last;
                nums[last] = nums[i];
            }
        }

        nums.resize(last+1);
        return nums.size();
    }
};