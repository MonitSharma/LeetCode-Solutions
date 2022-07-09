class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), a = 0, b = 0;
        int deq[n];
        deq[0] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (deq[a] - i > k) a++;
            nums[i] += nums[deq[a]];
            while (b >= a && nums[deq[b]] <= nums[i]) b--;
            deq[++b] = i;
        }
        return nums[0];
    }
};