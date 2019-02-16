// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j, 0, visit))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(const vector<vector<char>>& board, const string& word, int x, int y, int level, vector<vector<bool>>& visit)
    {
        if (level >= word.size())
        {
            return true;
        }
        
        if (x >= board.size() || y >= board[0].size() || x < 0 || y < 0 || visit[x][y] || board[x][y] != word[level])
        {
            return false;
        }
        
        visit[x][y] = true;        
        for (int i = x; i < board.size(); i++)
        {
            for (int j = y; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j + 1, level + 1, visit) ||
                    dfs(board, word, i, j - 1, level + 1, visit) ||
                    dfs(board, word, i + 1, j, level + 1, visit) ||
                    dfs(board, word, i - 1, j, level + 1, visit))
                {
                    return true;
                }                    
            }
        }        
        visit[x][y] = false;
        
        return false;
    }
};
