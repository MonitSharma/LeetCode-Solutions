class Solution {
    public int diagonalSum(int[][] mat) {
        
        int diagonalSum = 0;
        int len = mat.length - 1;
        
        for(int i=0; i<mat.length; i++){
            for(int j=0; j<mat[i].length; j++){
                
                if(i == j){
                    diagonalSum += mat[i][j];
                }
                else if(i == (len-j)){
                    diagonalSum += mat[i][j];
                }
            }
        }
        
        return diagonalSum;
    }
}