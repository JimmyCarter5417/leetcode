// A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
// Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.
// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
// Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.
// Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

// Note:
// Starting point is assumed to be valid, so it might not be included in the bank.
// If multiple mutations are needed, all mutations during in the sequence must be valid.
// You may assume start and end string is not the same.
 
// Example 1:
// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]

// return: 1

// Example 2:
// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

// return: 2
 
// Example 3:
// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

// return: 3


// 与127. Word Ladder一模一样
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res = 0;
        unordered_set<string> dict;
        queue<string> q;
        char elem[] = {'A', 'C', 'G', 'T'};
        
        dict.insert(bank.begin(), bank.end());
        q.push(start);
        
        while (!q.empty())
        {
            for (int i = q.size(); i > 0; i--)
            {
                string str = q.front();
                q.pop();

                if (str == end)
                {
                    return res;
                }

                for (int j = 0; j < str.size(); j++)
                {
                    string t = str;
                    
                    for (int k = 0; k < 4; k++)
                    {
                        t[j] = elem[k];
                        
                        if (dict.find(t) != dict.end() && t != str)
                        {
                            q.push(t);
                            dict.erase(t);
                        }
                    }
                }                
            }
            
            res++;
        }
        
        return -1;
    }
};