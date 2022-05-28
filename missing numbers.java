class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length,xo = n;
        for(int i=0;i<n;i++){
            xo^=i;
            xo^=nums[i];
        }
        return xo;
    }
}
