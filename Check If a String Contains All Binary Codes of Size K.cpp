class Solution {
public:
    bool hasAllCodes(string S, int K) {
        int len = S.size(), count = 1 << K;
        if (K > len) return false;
        int num = K > 1 ? stoi(S.substr(len - K + 1), 0, 2) << 1 : 0;
        vector<bool> seen(count, false);
        for (int i = len - K; ~i; i--) {
            num = (((S[i] - '0') << K) + num) >> 1;
            if (!seen[num]) seen[num] = true, count--;
            if (!count) return true;
            if (i < count) return false;
        }
        return false;
    }
};
