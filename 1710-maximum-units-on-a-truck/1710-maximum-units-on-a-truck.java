class Solution {
    public int maximumUnits(int[][] B, int T) {
        Arrays.sort(B, (a,b) -> b[1] - a[1]);
        int ans = 0;
        for (int[] b : B) {
            int count = Math.min(b[0], T);
            ans += count * b[1];
            T -= count;
            if (T == 0) return ans;
        }
        return ans;
    }
}