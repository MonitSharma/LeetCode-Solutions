class Solution {
    List<List<String>> ans;
    char[][] board;

    public List<List<String>> solveNQueens(int N) {
        ans = new ArrayList<>();
        board = new char[N][N];
        for (char[] row : board) Arrays.fill(row, '.');
        place(0,0,0,0);
        return ans;
    }

    private void place(int i, int vert, int ldiag, int rdiag) {
        int N = board.length;
        if (i == N) {
            List<String> res = new ArrayList<>();
            for (char[] row : board) res.add(new String(row));
            ans.add(res);
            return;
        }
        for (int j = 0; j < N; j++) {
            int vmask = 1 << j, lmask = 1 << (i+j), rmask = 1 << (N-i-1+j);
            if ((vert & vmask) + (ldiag & lmask) + (rdiag & rmask) > 0) continue;
            board[i][j] = 'Q';
            place(i+1, vert | vmask, ldiag | lmask, rdiag | rmask);
            board[i][j] = '.';
        }
    }
}
