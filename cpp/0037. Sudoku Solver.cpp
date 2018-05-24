// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Empty cells are indicated by the character '.'.


// A sudoku puzzle...


// ...and its solution numbers marked in red.

// Note:

// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique solution.
// The given board size is always 9x9.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty())
            return;
        
        int m = board.size();
        int n = board.front().size();
        if (m != 9 || n != 9)
            return;
            
        vector<vector<bool>> row(m, vector<bool>(n, false));
        vector<vector<bool>> col(m, vector<bool>(n, false));
        vector<vector<bool>> cell(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] != '.')
                {
                    int n = board[i][j] - '1';
                    row[i][n] = col[j][n] = cell[3 * (i / 3) + j / 3][n] = true;
                }
            }
        }
        
        dfs(board, 0, 0, row, col, cell);
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, 
        vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& cell)
    {
        int m = board.size();
        int n = board.front().size();
        
        if (x == m)
            return true;
        
        if (y == n)
            return dfs(board, x + 1, 0, row, col, cell);
        
        if (board[x][y] == '.')
        {
            for (int i = 0; i < 9; ++i)
            {
                if (!row[x][i] && !col[y][i] && !cell[3 * (x / 3) + y / 3][i])
                {
                    board[x][y] = i + '1';
                    row[x][i] = col[y][i] = cell[3 * (x / 3) + y / 3][i] = true;
                    
                    if (dfs(board, x, y + 1, row, col, cell))
                        return true;
                        
                    row[x][i] = col[y][i] = cell[3 * (x / 3) + y / 3][i] = false;
                    board[x][y] = '.';
                }
            }
        }
        else
        {
            return dfs(board, x, y + 1, row, col, cell);
        }
        
        return false;
    }
};
