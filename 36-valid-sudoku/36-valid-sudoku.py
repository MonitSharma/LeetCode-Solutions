class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        def is_valid_row():
            for row in board:
                if not is_valid(row):
                    return False
            return True
        
        def is_valid_col():
            for col in zip(*board):
                if not is_valid(col):
                    return False
            return True
        
        def is_valid_square():
            for i in (0,3,6):
                for j in (0,3,6):
                    square = [board[x][y] for x in range(i,i+3) 
                                        for y in range(j,j+3)]
                    if not is_valid(square):
                        return False
            return True
    
        def is_valid(value):
            res=[i for i in value if i!="."]
            return len(res)==len(set(res))
        
        return is_valid_row() and is_valid_col() and is_valid_square()