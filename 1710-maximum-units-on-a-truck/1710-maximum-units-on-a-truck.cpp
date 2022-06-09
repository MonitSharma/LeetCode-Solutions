class Solution {
public:
    int maximumUnits(vector<vector<int>>& B, int T) {
        sort(B.begin(), B.end(), [](auto& a, auto& b) { return b[1] < a[1];});
        int ans = 0;
        for (auto& b : B) {
            int count = min(b[0], T);
            ans += count * b[1], T -= count;
            if (!T) return ans;
        }
        return ans;
    }
};