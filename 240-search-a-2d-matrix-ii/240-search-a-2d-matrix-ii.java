class Solution {
    public boolean searchMatrix(int[][] M, int T) {
        int y = M.length, i = 0, j = M[0].length - 1;
        while (i < y && j >= 0) {
            int cell = M[i][j];
            if (cell == T) return true;
            else if (cell > T) j--;
            else i++;
        }
        return false;
    }
}