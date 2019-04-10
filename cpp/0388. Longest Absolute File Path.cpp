// Suppose we abstract our file system by a string in the following manner:

// The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

// dir
//     subdir1
//     subdir2
//         file.ext
// The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

// The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

// dir
//     subdir1
//         file1.ext
//         subsubdir1
//     subdir2
//         subsubdir2
//             file2.ext
// The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

// We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

// Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

// Note:
// The name of a file contains at least a . and an extension.
// The name of a directory or sub-directory will not contain a ..
// Time complexity required: O(n) where n is the size of the input string.

// Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.


class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream iss(input);
        int res = 0;
        string line;
        unordered_map<int, int> m; // 记录各个层次目录的长度

        while (getline(iss, line)) // 取一行字符串
        {
            int level = line.find_last_of('\t') + 1; // 前面的\t个数对应深度
            string s = line.substr(level); // \t后面是真正的名字

            if (s.find('.') != string::npos) // 文件
                res = max(res, m[level-1] + (int)s.size()); // 上一级目录长度 + 本文件名长度；只需要返回文件最大长度
            else // 目录
                m[level] = m[level-1] + (int)s.size() + 1; // 上一级目录长度 + 本目录名长度 + 1（即/分隔符）；每次新的相同层次，都会把老的层次长度覆盖，如subdir1和subdir2
        }
        
        return res;
    }
};