class Solution {
public:
    int minDistance(string W1, string W2) {
        int m = W1.size(), n = W2.size();
        if (m < n) swap(W1, W2), swap(n, m);
        vector<int> dpLast(n+1, 0), dpCurr(n+1, 0);
        for (char c1 : W1) {
            for (int j = 0; j < n; j++) 
                dpCurr[j+1] = c1 == W2[j]
                    ? dpLast[j] + 1
                    : max(dpCurr[j], dpLast[j+1]);
            swap(dpLast, dpCurr);
        }
        return m + n - 2 * dpLast[n];
    }
};