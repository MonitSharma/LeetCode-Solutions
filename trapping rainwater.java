class Solution 
{
    public int trap(int[] height)
    {
    if(height.length==0)
        return 0;
    int ans=0;
    //left[i] contains the maximum height of the pillar encountered before the ith pillar
    int left[]=new int[height.length];
    left[0]=height[0];
    //righ[i] contains the maximum height of the pillar encountered after the ith pillar
    int righ[]=new int[height.length];
    righ[righ.length-1]=height[height.length-1];
    for(int i=1;i<height.length;i++)
    {
      left[i]=Math.max(height[i],left[i-1]);
    }
    for(int i=height.length-2;i>-1;i--)
    {
        righ[i]=Math.max(height[i],righ[i+1]);
    }
    for(int i=1;i<height.length-1;i++)
    {
        ans=ans+Math.min(left[i],righ[i])-height[i];
    }
    return ans;
    }
}
