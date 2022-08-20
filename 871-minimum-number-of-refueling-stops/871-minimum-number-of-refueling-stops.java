class Solution {
    public int minRefuelStops(int T, int F, int[][] S) {
        int n = S.length, ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b - a);
        for (int i = 0; i <= n; i++) {
            int dist = i == n ? T : S[i][0];
            while (F < dist) {
                if (pq.size() == 0) return -1;
                F += pq.poll();
                ans++;
            }
            if (i < n) pq.add(S[i][1]);
        }
        return ans;
    }
}