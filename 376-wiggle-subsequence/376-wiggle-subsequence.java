class Solution {
    public int wiggleMaxLength(int[] N) {
        int len = N.length, i = 1, ans = 1;
        while (i < len && N[i] == N[i-1]) i++;
        if (i == len) return 1;
        boolean up = N[i-1] > N[i];
        for (; i < len; i++)
            if ((up && N[i] < N[i-1]) || (!up && N[i] > N[i-1])) {
                up = !up;
                ans++;
            }
        return ans;
    }
}