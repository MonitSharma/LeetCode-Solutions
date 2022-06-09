class Solution {
    public int swimInWater(int[][] grid) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int N = grid.length - 1, ans = grid[0][0], i = 0, j = 0;
        while (i < N || j < N) {
            for (int[] m : moves) {
                int ia = i + m[0], jb = j + m[1];
                if (ia < 0 || ia > N || jb < 0 || jb > N || grid[ia][jb] > 2500) continue;
                pq.add((grid[ia][jb] << 12) + (ia << 6) + jb);
                grid[ia][jb] = 3000;
            }
            int next = pq.poll();
            ans = Math.max(ans, next >> 12);
            i = (next >> 6) & ((1 << 6) - 1);
            j = next & ((1 << 6) - 1);
        }
        return ans;
    }
    private int[][] moves = {{1,0},{0,1},{-1,0},{0,-1}};
}