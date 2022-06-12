class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        char nmap[10001]{0};
        int total = 0, best = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            nmap[nums[right]]++, total += nums[right];
            while (nmap[nums[right]] > 1)
                nmap[nums[left]]--, total -= nums[left++];
            best = max(best, total);
        }
        return best;
    }
};