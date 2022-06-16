public class Solution {
    public int mySqrt(int x) {
        int left=1,right =x, result=0;
        while(left<right){
        int mid = left + (right - left)/2;
        if(mid<x/mid){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return (left==x/left)?left:left-1;
    }
}