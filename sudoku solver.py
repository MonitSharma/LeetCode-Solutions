class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        for i in range(9):
            for j in range(9):
                if(board[i][j] == "."):
                    board[i][j] = 0
        self.solve(board,0,0)
        
    def validation(self,board,row,col,number):
        for i in range(9):
            if(int(board[row][i]) == number):
                return False
        for j in range(9):
            if(int(board[j][col]) == number):
                return False
        grid_row = row - row % 3
        grid_col = col - col % 3
        for i in range(3):
            for j in range(3):
                if(int(board[grid_row + i][grid_col + j]) == number):
                    return False
        return True
        
    def solve(self,board,row,col):
        if(col == 9):
            if(row == 8):
                return True
            row += 1
            col = 0

        if(int(board[row][col]) > 0):
            return self.solve(board,row,col+1)

        for num in range(1,10):
            if(self.validation(board,row,col,num)):
                board[row][col] = str(num)
                if(self.solve(board,row,col+1)):
                    return True
            board[row][col] = 0  
        return False
