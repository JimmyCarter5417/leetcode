//Given an input string, reverse the string word by word.
//
//Example:  
//
//Input: "the sky is blue",
//Output: "blue is sky the".
//Note:
//
//A word is defined as a sequence of non-space characters.
//Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
//You need to reduce multiple spaces between two words to a single space in the reversed string.
//Follow up: For C programmers, try to solve it in-place in O(1) space.
//


class Solution {
public:
    void reverseWords(string &s) {
        int write_pos = 0;
        int word_start_pos = 0;
        int cur = 0;
        bool flag = false;
        // 两次翻转，注意记录写入位置和处理空格即可
        while (cur < s.size())
        {
            while (cur < s.size() && s[cur] == ' ')
                ++cur;
            if (cur == s.size())
                break;

            if (flag)
                s[write_pos++] = ' ';
            word_start_pos = write_pos;

            while (cur < s.size() && s[cur] != ' ')
                s[write_pos++] = s[cur++];

            reverse(s, word_start_pos, write_pos - 1);
            flag = true;
        }

        s.resize(write_pos);
        std::reverse(s.begin(), s.end());
    }

    void reverse(string& s, int start, int end)
    {
        while (start < end)
            swap(s[start++], s[end--]);
    }
};

