class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string res1 = to_string(N);
        sort(res1.begin(), res1.end());
        for (int i = 0; i < 30; i++) {
            string res2 = to_string(1 << i);
            sort(res2.begin(), res2.end());
            if (res1 == res2) return true;
        }
        return false;
    }
};