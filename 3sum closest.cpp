class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3){
            return 0;
        }

        sort(nums.begin(), nums.end());

        int i = 0;
        int sum, minDiff = INT_MAX;

        while(i < nums.size() - 2){
            int left = i + 1;
            int right = nums.size() - 1;
            while(right > left){
                int temp = nums[i] + nums[left] + nums[right];
                int diff = abs(temp - target);

                if(diff == 0){
                    return target;
                }

                if(diff < minDiff){
                    minDiff = diff;
                    sum = temp;
                }

                if(temp < target){
                    left++;
                }
                else{
                    right--;
                }
            }
            i++;
        }

    return sum;
  }
};
