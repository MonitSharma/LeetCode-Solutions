class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] ord = new int[n][2];
        for (int i = 0; i < n; i++)
            ord[i] = new int[] {efficiency[i], speed[i]};
        Arrays.sort(ord, (a, b) -> Integer.compare(b[0], a[0]));
        PriorityQueue<Integer> sppq = new PriorityQueue<>();
        long totalSpeed = 0, best = 0;
        for (int[] pair : ord) {
            int spd = pair[1];
            sppq.add(spd);
            if (sppq.size() <= k) totalSpeed += spd;
            else totalSpeed += spd - sppq.poll();
            best = Math.max(best, totalSpeed * pair[0]);
        }
        return (int)(best % 1000000007);
    }
}