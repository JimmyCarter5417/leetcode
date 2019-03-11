// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.


class Trie {
    class Node
    {
    public:
        Node(char c = 0)
            : ch(c)
            , end(false)
        {
            
        }
        
        ~Node()
        {
            for (auto child: vnode)
                if (child != nullptr)
                    delete child;
        }
        
        char getChar()
        {
            return ch;
        }
        
        void setEnd(bool val)
        {
            end = val;
        }
        
        bool getEnd()
        {
            return end;
        }
        
        Node* getChildNode(char ch)
        {
            for (auto child: vnode)
            {
                if (child != nullptr)
                {
                    if (ch == child->getChar())
                        return child;
                }
            }
            
            return nullptr;
        }
        
        Node* addChildNode(char ch)
        {
            vnode.push_back(new Node(ch));
            return vnode.back();
        }
        
    private:  
        char ch;
        bool end;
        vector<Node*> vnode;
    };
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node;
    }
    
    ~Trie()
    {
        if (root != nullptr)
        {
            delete root;
            root = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (search(word))
            return ;
            
        Node* cur = root;
        for (char ch: word)
        {
            Node* child = cur->getChildNode(ch);
            if (child == nullptr)
                child = cur->addChildNode(ch);
            
            cur = child;
        }
        
        cur->setEnd(true);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        
        for (char ch: word)
        {
            Node* child = cur->getChildNode(ch);
            if (child == nullptr)
                return false;
            
            cur = child;
        }
        
        return cur != nullptr && cur->getEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        
        for (char ch: prefix)
        {
            Node* child = cur->getChildNode(ch);
            if (child == nullptr)
                return false;
            
            cur = child;
        }
        
        return true;
    }
    
private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
