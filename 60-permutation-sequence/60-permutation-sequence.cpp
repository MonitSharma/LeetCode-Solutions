class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums; 
        string res;
        int fact = 1;
        for(int i=1;i<=n;i++){
            fact *= i;          // 1,2,6,24
            nums.push_back(i); // [1] [1,2] [1,2,3] [1,2,3,4]
        }
        k = k - 1; // 0 base indexing  17-1 = 16
        fact = fact/nums.size();  //24/4 = 6 (3! perm are more possible with remaining 3 elements as 1 out of 4 would be used)
        while(true){
            res += to_string(nums[k/fact]); // 16/6 = 2
            nums.erase(nums.begin() + k/fact); // [1,2,4]
            if(nums.size()==0){
                return res;
            }
            k = k%fact; // 16%6=4 
            fact = fact/nums.size(); // 6/3 = 2 for coming elements we have arr of 2 ele only out of 3 , 1 would be contributing in res and 2! is 2 so fact is updated
        }
        return res;
    }
};