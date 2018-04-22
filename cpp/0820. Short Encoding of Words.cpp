// Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

// For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

// Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

// What is the length of the shortest reference string S possible that encodes the given words?

// Example:

// Input: words = ["time", "me", "bell"]
// Output: 10
// Explanation: S = "time#bell#" and indexes = [0, 2, 5].
// Note:

// 1 <= words.length <= 2000.
// 1 <= words[i].length <= 7.
// Each word has only lowercase letters.

class Solution {
    struct TrieNode
    {   
        unordered_map<char, TrieNode*> next;          
    };
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        TrieNode* root = new TrieNode;
        unordered_map<TrieNode*, int> leaves;
        
        for (int i = 0; i < words.size(); i++)
        {
            TrieNode* cur = root;
            for (int j = words[i].size() - 1; j >= 0; --j)
            {
                if (cur->next.find(words[i][j]) == cur->next.end())
                    cur->next[words[i][j]] = new TrieNode;
                cur = cur->next[words[i][j]];
            }
            
            leaves[cur] = words[i].size() + 1;
        }
        
        for (auto itr = leaves.begin(); itr != leaves.end(); ++itr)
        {
            if (itr->first->next.empty())
                res += itr->second;
        }
        
        return res;
    }
};
