class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        int len = A.size();
        long ans = 0;
        unordered_map<int, long> fmap;
        for (int num : A) {
            long ways = 1;
            double lim = sqrt(num);
            for (int j = 0, fA = A[0]; fA <= lim; fA = A[++j]) {
                if (num % fA != 0) continue;
                int fB = num / fA;
                if (fmap.find(fB) != fmap.end())
                    ways += fmap[fA] * fmap[fB] * (fA == fB ? 1 : 2);
            }
            fmap[num] = ways;
            ans = (ans + ways) % 1000000007;
        }
        return (int)ans;
    }
};