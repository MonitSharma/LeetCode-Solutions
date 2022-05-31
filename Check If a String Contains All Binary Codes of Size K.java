class Solution {
    public boolean hasAllCodes(String S, int K) {
        int len = S.length(), count = 1 << K;
        if (K > len) return false;
        int num = K > 1 ? Integer.parseInt(S.substring(len - K + 1), 2) << 1 : 0;
        boolean[] seen = new boolean[count];
        for (int i = len - K; i >= 0; i--) {
            num = (((S.charAt(i) - '0') << K) + num) >> 1;
            if (!seen[num]) {
                seen[num] = true;
                count--;
            }
            if (count == 0) return true;
            if (i < count) return false;
        }
        return false;
    }
}
