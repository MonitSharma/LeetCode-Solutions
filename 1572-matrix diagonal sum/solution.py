class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        result = 0
        for i in range(n):
            result += mat[i][i] + mat[i][n - i - 1]
        if n % 2 == 1:
            result -= mat[n // 2][n // 2]
        return result