// Design a Tic-tac-toe game that is played between two players on a n x n grid.

// You may assume the following rules:

// A move is guaranteed to be valid and is placed on an empty block.
// Once a winning condition is reached, no more moves is allowed.
// A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
// Example:
// Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

// TicTacToe toe = new TicTacToe(3);

// toe.move(0, 0, 1); -> Returns 0 (no one wins)
// |X| | |
// | | | | // Player 1 makes a move at (0, 0).
// | | | |

// toe.move(0, 2, 2); -> Returns 0 (no one wins)
// |X| |O|
// | | | | // Player 2 makes a move at (0, 2).
// | | | |

// toe.move(2, 2, 1); -> Returns 0 (no one wins)
// |X| |O|
// | | | | // Player 1 makes a move at (2, 2).
// | | |X|

// toe.move(1, 1, 2); -> Returns 0 (no one wins)
// |X| |O|
// | |O| | // Player 2 makes a move at (1, 1).
// | | |X|

// toe.move(2, 0, 1); -> Returns 0 (no one wins)
// |X| |O|
// | |O| | // Player 1 makes a move at (2, 0).
// |X| |X|

// toe.move(1, 0, 2); -> Returns 0 (no one wins)
// |X| |O|
// |O|O| | // Player 2 makes a move at (1, 0).
// |X| |X|

// toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
// |X| |O|
// |O|O| | // Player 1 makes a move at (2, 1).
// |X|X|X|
// Follow up:
// Could you do better than O(n2) per move() operation?

// Hint:

// Could you trade extra space such that move() operation can be done in O(1)?
// You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.


// solution I: 直接遍历行、列、对角线
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, 0));   
    }

    int move(int row, int col, int player) {
        int i = 0;
        int j = 0;
        int n = board.size();

        board[row][col] = player;

        // 先遍历第row行，看是否结束
        for (j = 1; j < n; ++j) 
        {
            if (board[row][j] != board[row][j - 1]) // 一旦碰到对方玩家棋子，即可结束循环
                break;
        }
        if (j == n) 
            return player;

        // 再遍历第col列
        for (i = 1; i < n; ++i)
        {
            if (board[i][col] != board[i - 1][col]) 
                break;
        }
        if (i == n) 
            return player;

        // 遍历对角线
        if (row == col) 
        {
            for (i = 1; i < n; ++i) 
            {
                if (board[i][i] != board[i - 1][i - 1]) 
                    break;
            }
            if (i == n) 
                return player;
        }

        // 遍历反对角线
        if (row + col == n - 1) 
        {
            for (i = 1; i < n; ++i) 
            {
                if (board[n - i - 1][i] != board[n - i][i - 1]) 
                    break;
            }
            if (i == n) 
                return player;
        }

        return 0;
    }
    
private:
    vector<vector<int>> board;
};

// solution II: 优化
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): 
        rows(n), cols(n), N(n), diag(0), rev_diag(0) 
    {

    }

    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1; // 1号玩家加一，2号玩家减一

        // 行、列、对角线、反对角线
        rows[row] += add; 
        cols[col] += add;
        diag += (row == col ? add : 0);
        rev_diag += (row == N - col - 1 ? add : 0);

        // 一旦某个计数为正负N，即代表胜利
        return (abs(rows[row]) == N || abs(cols[col]) == N || abs(diag) == N || abs(rev_diag) == N) ? player : 0;
    }

private:
    vector<int> rows;
    vector<int> cols;
    int         diag;
    int         rev_diag;
    int         N;
};