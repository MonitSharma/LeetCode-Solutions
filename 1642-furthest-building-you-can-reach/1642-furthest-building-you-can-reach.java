class Solution {
    public int furthestBuilding(int[] H, int B, int L) {
        int len = H.length - 1;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < len; i++) {
            int diff = H[i+1] - H[i];
            if (diff > 0) {
                if (L > 0) {
                    pq.add(diff);
                    L--;
                } else if (pq.size() > 0 && diff > pq.peek()) {
                    pq.add(diff);
                    B -= pq.poll();
                } else B -= diff;
                if (B < 0) return i;
            }
        }
        return len;
    }
}