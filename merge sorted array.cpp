class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        vector<int> nums;
        while(1)
        {
            if(i==m)
            {
                while(j<n)
                {
                    nums.push_back(nums2[j]);
                    j++;
                }
                break;
            }
            
            else if(j==n)
            {
                while(i<m)
                {
                    nums.push_back(nums1[i]);
                    i++;
                }
                break;
            }
            
            else
            {
                if(nums1[i] < nums2[j])
                {
                    nums.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    nums.push_back(nums2[j]);
                    j++;
                }
            }
        }
        
        for(i=0; i<m+n; i++)
            nums1[i] = nums[i];
    }
};
