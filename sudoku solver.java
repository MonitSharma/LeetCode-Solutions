class Solution {
    public void solveSudoku(char[][] board) {
        boolean[][] row = new boolean[9][10];
        boolean[][] col = new boolean[9][10];
        boolean[][][] square = new boolean[3][3][10];
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') continue;
                int v = board[i][j] - '0';
                row[i][v] = true;
                col[j][v] = true;
                square[i/3][j/3][v] = true;
            }
        }
        solve(board,0,row,col,square);
    }
    public boolean solve(char[][] board,int index,boolean[][] row,boolean[][] col,boolean[][][] square) {
        if(index > 80) return true;
        int i = index/9, j = index%9;
        if(board[i][j] != '.') {
            return solve(board,index+1,row,col,square);
        }
        for(int v=1;v<=9;v++) {
            if(row[i][v] || col[j][v] || square[i/3][j/3][v]) continue;
            row[i][v] = true;
            col[j][v] = true;
            square[i/3][j/3][v] = true;
            board[i][j] = (char) (v + '0');
            if(solve(board,index+1,row,col,square)) return true;
            row[i][v] = false;
            col[j][v] = false;
            square[i/3][j/3][v] = false;
            board[i][j] = '.';
        }
        return false;
    }
}
