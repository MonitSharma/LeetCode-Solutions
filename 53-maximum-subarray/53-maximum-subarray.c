int maxSubArray(int* nums, int n) {
        int ans=nums[0],i,sum=0;
        for(i=0;i<n;i++){
            sum+=nums[i];
            if(ans<sum)ans=sum;
            if(sum<0)sum=0;
        }
        return ans;
}