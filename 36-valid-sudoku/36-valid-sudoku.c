bool isValidSudoku(char** board, int boardSize, int* boardColSize){

int i=0, j=0;
int rowSet[9][10] = {0};
int colSet[9][10] = {0};
int box[3][3][10] = {0};    
for(i = 0; i<9; i++){
    for(j=0; j<9; j++){
        if(board[i][j] != '.'){
            int val = (int)board[i][j] - 48;//Converting to int
            if(rowSet[i][val] != 0)
                return false;
            if(colSet[j][val] != 0)
                return false;
            if(box[i/3][j/3][val] !=0)
                return false;   
            box[i/3][j/3][val] +=1;
            rowSet[i][val] +=1;
            colSet[j][val] +=1;
        }
    }
}
return true;
}