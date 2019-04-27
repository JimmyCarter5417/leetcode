// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

// Example:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"] 

// Note:
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        // 先分组
        unordered_set<char> s1{'q','w','e','r','t','y','u','i','o','p', 'Q','W','E','R','T','Y','U','I','O','P'};
        unordered_set<char> s2{'a','s','d','f','g','h','j','k','l', 'A','S','D','F','G','H','J','K','L'};
        unordered_set<char> s3{'z','x','c','v','b','n','m', 'Z','X','C','V','B','N','M'};
        
        for (const string& word: words)
        {
            if (word.empty())
            {
                continue;
            }    
            
            // 找到可能的对应行
            unordered_set<char>* p = nullptr;
            if (s1.find(word.front()) != s1.end())
            {
                p = &s1;
            }    
            else if (s2.find(word.front()) != s2.end())
            {
                p = &s2;
            }    
            else
            {
                p = &s3;
            }    
                
            bool ok = true;
            for (int i = 1; i < word.size(); ++i)
            {
                if (p->find(word[i]) == p->end())
                {
                    ok = false; // 踢掉
                    break;
                }
            }
            
            if (ok)
            {
                res.push_back(word);
            }    
        }
        
        return res;
    }
};