class Solution {
public:
    int divide(int A, int B) {
        int ans = 0, sign = A > 0 == B > 0 ? 1 : -1;
        if (B == -2147483648) return A == B;
        if (A == -2147483648)
            if (B == 1) return -2147483648;
            else if (B == -1) return 2147483647;
            else A += abs(B), ans++;
        A = abs(A), B = abs(B);
        for (int i = 0; A >= B; i = 0) {
            while (A >> i >= B) i++;
            A -= B << i - 1, ans += 1 << i - 1;
        }
        return sign < 0 ? -ans : ans;
    }
};
