class Solution {
    public int jump(int[] N) {
        int len = N.length - 1, curr = -1, next = 0, ans = 0;
        for (int i = 0; next < len; i++) {
            if (i > curr) {
                ans++;
                curr = next;
            };
            next = Math.max(next, N[i] + i);
        };
        return ans;
    };
};