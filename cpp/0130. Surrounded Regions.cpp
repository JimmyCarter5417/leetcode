//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//Example:
//
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be:
//
//X X X X
//X X X X
//X X X X
//X O X X
//Explanation:
//
//Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
//

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;

        // 对于边缘的O，需要递归修改
        for (int i = 0; i < board.size(); ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, board[0].size() - 1);
            /*bfs(board, i, 0);
            bfs(board, i, board[0].size() - 1);*/
        }
        for (int i = 0; i < board[0].size(); ++i)
        {
            dfs(board, 0, i);
            dfs(board, board.size() - 1, i);
            /*bfs(board, 0, i);
            bfs(board, board.size() - 1, i);*/
        }
        // 将递归修改的O改回来
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == '$')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O') // 按要求改写内部的O
                    board[i][j] = 'X';
            }
        }
    }
    
    void bfs(vector<vector<char>>& board, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        
        while (!q.empty())
        {
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            
            if (xx < 0 || xx > board.size() - 1 || yy < 0 || yy > board[0].size() - 1 || board[xx][yy] == 'X' || board[xx][yy] == '$')
                continue;
            
            board[xx][yy] = '$';
            
            q.push({xx - 1, yy});
            q.push({xx, yy + 1});
            q.push({xx + 1, yy});
            q.push({xx, yy - 1});
        }
    }
    
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if (x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() - 1 || board[x][y] == 'X' || board[x][y] == '$')
            return;
            
        board[x][y] = '$';
        
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
    }
};
