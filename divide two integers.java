class Solution {
    public int divide(int A, int B) {
        if (A == -2147483648 && B == -1) return 2147483647;
        int ans = 0, sign = A > 0 == B > 0 ? 1 : -1;
        if (A < 0) A = -A;
        if (B < 0) B = -B;
        if (A == B) return sign;
        for (int i = 0, val = B; A - B >= 0; i = 0, val = B) {
            while (val > 0 && A - val >= 0) val = B << ++i;
            A -= B << i - 1;
            ans += 1 << i - 1;
        }
        return sign < 0 ? -ans : ans;
    }
}
