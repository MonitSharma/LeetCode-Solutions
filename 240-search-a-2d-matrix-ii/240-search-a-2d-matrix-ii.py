class Solution:
    def searchMatrix(self, M: List[List[int]], T: int) -> bool:
        y, i, j = len(M), 0, len(M[0]) - 1
        while i < y and ~j:
            cell = M[i][j]
            if cell == T: return True
            elif cell > T: j -= 1
            else: i += 1
        return False