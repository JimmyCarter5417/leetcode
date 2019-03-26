// Write a function to generate the generalized abbreviations of a word.

// Example:

// Given word = "word", return the following list (order does not matter):

// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res{word};
        helper(word, 0, res);
        return res;
    }

    void helper(const string& word, int pos, vector<string> &res) 
    {
        for (int i = pos; i < word.size(); ++i) 
        {
            for (int j = 1; i + j <= word.size(); ++j) // 注意，循环终止条件
            {
                string t = word.substr(0, i);
                t += to_string(j) + word.substr(i + j); // 缩写中间j个字符，生成新的缩写形式
                res.push_back(t); // 保存

                helper(t, i + 1 + to_string(j).size(), res); // 对t从缩写之后的位置，继续递归
            }
        }
    }
};