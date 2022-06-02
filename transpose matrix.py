class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        transpose_matrix = [[0 for i in range(0, len(matrix))] for j in range(0, len(matrix[0]))]
        
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[0])):
                transpose_matrix[j][i] = matrix[i][j]

        return transpose_matrix
