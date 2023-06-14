class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
           int n = nums.length;
        long ans = 0;
        Map<Integer, Integer>[] frequencyArrayMap = new Map[n];
        for(int i=0;i<n;i++){
            frequencyArrayMap[i]=new HashMap<>();
        }
        for(int i=0;i<n;i++){
           for(int  j=0;j<i;j++){
               long commondiff = (long)nums[i]-(long)nums[j];
               if(commondiff<Integer.MIN_VALUE || commondiff> Integer.MAX_VALUE)continue;
               int diff =(int)commondiff;
               int prevFreq=frequencyArrayMap[j].getOrDefault(diff,0);
               int currFreq=frequencyArrayMap[i].getOrDefault(diff,0);
               ans+=prevFreq;
               frequencyArrayMap[i].put(diff,prevFreq+currFreq+1);
           }
        }
        return (int)ans;
        
    }
}