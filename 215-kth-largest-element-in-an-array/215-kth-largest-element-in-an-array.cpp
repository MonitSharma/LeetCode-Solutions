class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> min_heap; //min heap implemetation
        for (int num : nums){
            min_heap.insert(num);
            if(min_heap.size() > k) min_heap.erase(min_heap.begin());

        }

        return *min_heap.begin();
    }
};