class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),xo = n;
        for(int i=0;i<n;i++){
            xo^=i;
            xo^=nums[i];
        }
        return xo;
    }
};
