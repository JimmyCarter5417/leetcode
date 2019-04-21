// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

// Example 1:
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5

// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Example 2:
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Output: 0

// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


// BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 1; // 即BFS当前遍历的层数
        unordered_set<string> dict; // 字典
        queue<string> q;
        
        dict.insert(wordList.begin(), wordList.end());
        q.push(beginWord);
        
        while (!q.empty())
        {
            for (int i = q.size(); i > 0; i--)
            {
                string str = q.front();
                q.pop();
                
                if (str == endWord) // 找到目的string，返回当前层数即可
                {
                    return res;
                }
                
                for (int j = 0; j < str.size(); j++) // 逐个字符替换
                {
                    string t = str;
                    
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        t[j] = ch;
                        
                        if (dict.find(t) != dict.end() && t != str) // 不能是原字符串
                        {
                            q.push(t);
                            // 此处可以直接从字典删除t，因为如果t是合法的中间字符串，此处必然是最先遍历到的位置
                            dict.erase(t); // 字典的字符串只能使用一次
                        }
                    }
                }                
            }
            
            res++;
        }
        
        return 0;
    }
};