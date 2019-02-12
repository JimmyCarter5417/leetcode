// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
  // "((()))",
  // "(()())",
  // "(())()",
  // "()(())",
  // "()()()"
// ]

// solution I
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }
    
    // �������ŷֱ�����ݹ�
    void dfs(int left, int right, string out, vector<string>& res)
    {
        // һ��Ҫ�ȹ��˷Ƿ����ʽ
        if (left > right)
        {
            return;
        }
        // ��������
        if (left == 0 && right == 0)
        {
            res.push_back(out);
            return;
        }
        
        if (left > 0)
        {
            dfs(left - 1, right, out + '(', res);
        }
        
        if (right > 0)
        {
            dfs(left, right - 1, out + ')', res);
        }
    }
};

// solution II
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        if (n == 1)
        {
            res.push_back("()");
            return res;
        }
        
        set<string> s; // ע��ȥ��
        vector<string> v = generateParenthesis(n - 1);
        for (const string& str: v)
        {
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == '(') // �������Ų���һ�����Ŷ�
                {
                    string tmp = str;
                    tmp.insert(i + 1, "()");
                    s.insert(tmp);
                }
            }
            
            s.insert("()" + str);
        }
        
        return vector<string>(s.begin(), s.end());
    }
};