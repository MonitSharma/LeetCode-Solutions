int brutal_solve(char** board, int pos){
    int i, j, ris = 0, k, flag = 1;
    while(pos <81 && board[pos/9][pos%9]!='.')  pos++;
    if(pos>=81){
        ris = 1;
        return ris;
    }

    for(k=1; k<=9; k++){
        flag = 1;
        for(i=0; i<9;i++){
            if(board[pos/9][i]==(k+'0')) flag = 0;
            if(board[i][pos%9]==(k+'0')) flag = 0;
        }
        for(i=(pos/9)-((pos/9)%3); i<(pos/9)-((pos/9)%3)+3; i++)
            for(j=(pos%9)-((pos%9)%3); j<(pos%9)-((pos%9)%3)+3; j++)
                if(board[i][j]==k +'0') flag = 0;
        if(flag){
            board[pos/9][pos%9] = k+'0';
            ris = brutal_solve(board, pos +1);
            if(ris==0)
                board[pos/9][pos%9] = '.';
            else
                return ris;

        }
    }
    return ris;
}


void updateExclusion(int exclusion[9][9][9], int i, int j, int value){
    int r, c, k, m, n;
    for(k=0;k<9;k++){
        exclusion[i][j][k]=0;
        exclusion[k][j][value]=0;
        exclusion[i][k][value]=0;
    }
    r = (i/3)*3;
    c = (j/3)*3;
    for(m=0; m<3; m++, r++)
        for(n=0; n<3; n++)
            exclusion[r][c+n][value]=0;
    return;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){

    int exclusion[9][9][9], flag=1;
    int i, j, k, r, c, value, iter1, iter2, squareR, squareC, squareRlim, squareClim;
    int rToAdd, cToAdd;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            for(k=0;k<9;k++)
                exclusion[i][j][k]=1;
   
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
                if(board[i][j]!='.'){
                    value = board[i][j] - 1 - '0';
                    updateExclusion(exclusion, i, j, value);
                }
      /*this flag will be used for checking if a new value has been inserted in the Sudoku scheme*/
    while(flag){
        flag = 0;
        for(iter1=0;iter1<9;iter1++){
            for(squareR=0;squareR<3;squareR++){
                for(squareC=0;squareC<3;squareC++){
                    value =0;
                    squareRlim = squareR*3;
                    squareClim = squareC*3;
                    for(r=squareRlim;r<squareRlim+3&&flag==0;r++){
                        for(c=squareClim;c<squareClim+3&&flag==0;c++){
                            if(exclusion[r][c][iter1]!=0){
                                rToAdd=r;
                                cToAdd=c;
                                
                            }
                            value += exclusion[r][c][iter1];
                        }
                    }
                    if(value == 1){
                        board[rToAdd][cToAdd] = iter1+1+'0';
                        flag++;
                        updateExclusion(exclusion, rToAdd, cToAdd, iter1);
                    }
                }
            }
            for(r=0;r<9;r++){
                value = 0;
                for(c=0;c<9;c++){
                    if(exclusion[r][c][iter1]!=0)
                        cToAdd=c;
                    value += exclusion[r][c][iter1];
                }
                if(value == 1){
                    board[r][cToAdd] = iter1+1 +'0';
                    flag++;
                    updateExclusion(exclusion, r, cToAdd, iter1);
                }
            }

            for(c=0;c<9;c++){
                value = 0;
                for(r=0;r<9;r++){
                    if(exclusion[r][c][iter1]!=0)
                        rToAdd=r;
                    value += exclusion[r][c][iter1];
                }
                if(value == 1){
                    board[rToAdd][c] = iter1+1 + '0';
                    flag++;
                    updateExclusion(exclusion, rToAdd, c, iter1);
                }
            }
        }
    }
    brutal_solve(board, 0);
    return;
    
    
}
