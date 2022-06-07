class Solution 
{
public:
    int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
public:
    int min(int a,int b)
    {
        if(b>a)
            return a;
        else
            return b;
    }
public:
    int trap(vector<int>& height)
    {
    int left=0; 
    int righ=height.size()-1; 
    int lmax=-1; 
    int rmax=-1; 
    int ans=0; 
    while(righ>left) 
    { 
        //We rely on the minimum of the both 
        if(height[left]<height[righ]) 
        { //Update left max if the current height is greater 
            if(height[left]>=lmax) 
                lmax=height[left]; 
            //else add the water trapped to the answer 
            else ans=ans+lmax-height[left]; left=left+1; 
        } 
        else 
        { //If current height is greater than right max update 
            if(height[righ]>=rmax) 
                rmax=height[righ]; 
            //else add to the answer 
            else 
                ans=ans+rmax-height[righ]; 
            righ=righ-1; 
        }
       }
    return ans;
    }
};
