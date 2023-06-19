class Solution {
public:
    int largestAltitude(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        vector<int> ans(n+1);
        ans.push_back(0);
       
        int i=1;
        for(int i=1; i<n+1; i++){
            ans[i]=ans[i-1]+nums[i-1];
        }

        for(int i=0; i<ans.size();i++){
            maxi = max(maxi,ans[i]);
        }


       
       return maxi;
    }
};