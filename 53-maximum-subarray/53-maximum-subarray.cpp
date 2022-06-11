class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int t=nums[i-1]+nums[i];
            nums[i]=max(nums[i],t);
            sum=max(sum,nums[i]);
        }
        return sum;
    }
};
