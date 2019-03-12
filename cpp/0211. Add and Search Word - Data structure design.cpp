//Design a data structure that supports the following two operations:
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
//Example:
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//Note:
//You may assume that all words are consist of lowercase letters a-z.
//


class WordDictionary {
    struct TrieNode
    {
        TrieNode()
            : isWord(false)
        {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
        
        ~TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                delete child[i];
                child[i] = nullptr;
            }
        }
        
        TrieNode* child[26];
        bool isWord;
    };
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    
    ~WordDictionary()
    {
        delete root;
        root = nullptr;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for (char ch: word)
        {
            if (!cur->child[ch - 'a'])
                cur->child[ch - 'a'] = new TrieNode;
            
            cur = cur->child[ch - 'a'];
        }
        
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root, 0);
    }
    
    bool search(const string& word, TrieNode* node, int idx)
    {
        if (idx == word.size())
            return node->isWord;
            
        if (word[idx] == '.') // 注意处理通配符
        {
            for (auto p: node->child)
                if (p && search(word, p, idx + 1))
                    return true;
                    
            return false;
        }
        else // 如果仅仅精确匹配的话，就不需要递归了
        {
            TrieNode* p = node->child[word[idx] - 'a'];
            return p && search(word, p, idx + 1);
        }
    }
    
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

