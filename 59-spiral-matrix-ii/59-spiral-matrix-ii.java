class Solution {
    public int[][] generateMatrix(int n) {
        int[][] spiralMatrix = new int[n][n];
        int num=1;
        char dir='E';
        int l=0, t=0, r=n-1, d=n-1;
        while(l<=r && t<=d) {
            if(dir == 'E') {
                for(int i=l; i<=r; i++) {
                    spiralMatrix[t][i] = num++;
                }
                t++;
                dir='S';
            }
            else if(dir=='S') {
                for(int i=t; i<=d; i++) {
                    spiralMatrix[i][r] = num++;
                }
                r--;
                dir='W';
            }
            else if(dir=='W') {
                for(int i=r; i>=l; i--) {
                    spiralMatrix[d][i] = num++;
                }
                d--;
                dir='N';
            }
            else {
                for(int i=d; i>=t; i--) {
                    spiralMatrix[i][l] = num++;
                }
                l++;
                dir='E';
            }
        }
        return spiralMatrix;
    }
}