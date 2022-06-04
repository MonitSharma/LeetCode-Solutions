class Solution {
    inline int getBox(int i, int j) {
        return i / 3 * 3 + j / 3;
    }
    inline bool contains(int bitset, int bit) {
        return bitset & (1 << bit);
    }
    inline void setBit(int& bitset, int bit) {
        bitset |= (1 << bit); 
    }
    inline void removeBit(int& bitset, int bit) {
        bitset &= ~(1 << bit);
    }
    bool backtrack(vector<vector<char>>& board, int v, vector<int>& row, vector<int>& col, vector<int>& box) {
        if (v > 80) return true;
        
        int i = v / 9, j = v % 9;
        if (board[i][j] != '.') return backtrack(board, v + 1, row, col, box);
        
        for (int num = 1; num <= 9; ++num) {
            if (!contains(row[i], num) && !contains(col[j], num) && !contains(box[getBox(i, j)], num)) {
                setBit(row[i], num);
                setBit(col[j], num);
                setBit(box[getBox(i, j)], num);
                board[i][j] = num + '0';
                
                if (backtrack(board, v + 1, row, col, box)) return true;
                
                removeBit(row[i], num);
                removeBit(col[j], num);
                removeBit(box[getBox(i, j)], num);
                board[i][j] = '.';
            }
        }
        
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0), col(9, 0), box(9, 0);
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    setBit(row[i], board[i][j] - '0');
                    setBit(col[j], board[i][j] - '0');
                    setBit(box[getBox(i, j)], board[i][j] - '0');
                }
            }
        }
        
        backtrack(board, 0, row, col, box);
    }
};
