//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
//Example:
//
//Input: 
//words = ["oath","pea","eat","rain"] and board =
//[
//  ['o','a','a','n'],
//  ['e','t','a','e'],
//  ['i','h','k','r'],
//  ['i','f','l','v']
//]
//
//Output: ["eat","oath"]
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.
//


class Solution {
public:
    struct TrieNode
    {
        TrieNode()
        {
            for (TrieNode*& node: child)
                node = nullptr;
        }
        
        ~TrieNode()
        {
            for (TrieNode* node: child)
            {
                delete node;
                node = nullptr;
            }
        }
        
        TrieNode* child[26];
        string word;
    };
    
    struct Trie
    {
        Trie()
        {
            root = new TrieNode;
        }
        
        ~Trie()
        {
            delete root;
            root = nullptr;
        }
        
        void insert(const string& s)
        {
            TrieNode* p = root;
            for (char ch: s)
            {
                if (!p->child[ch - 'a'])
                    p->child[ch - 'a'] = new TrieNode;
                
                p = p->child[ch - 'a'];
            }
            
            p->word = s;
        }
        
        TrieNode* root;
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board.front().empty())
            return {};
            
        Trie T; // 用所有words创建一个trie
        for (const string& word: words)
            T.insert(word);
            
        int m = board.size();
        int n = board.front().size();
        vector<string> res;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        // 从每一个点开始扩散
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (T.root->child[board[i][j] - 'a'])
                    dfs(board, i, j, T.root->child[board[i][j] - 'a'], visit, res);
        
        return res;
    }
    
    void dfs(const vector<vector<char>>& board, int x, int y, TrieNode* node, vector<vector<bool>>& visit, vector<string>& res)
    {
        if (!node->word.empty())
        {
            res.push_back(node->word);
            node->word.clear();
        }
            
        visit[x][y] = true;
            
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        for (int i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < board.size() && 
                yy >= 0 && yy < board.front().size() && 
                !visit[xx][yy] && 
                node->child[board[xx][yy] - 'a'])
                dfs(board, xx, yy, node->child[board[xx][yy] - 'a'], visit, res); // node->child[board[xx][yy] - 'a']这个node要更新
        }
        
        visit[x][y] = false;
    }
};

