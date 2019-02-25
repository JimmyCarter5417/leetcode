// The API: int read4(char *buf) reads 4 characters at a time from a file.
// The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
// Note:
// The read function will only be called once for each test case.


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
  int read(char *buf, int n) {
      int res = 0;
      
      while (n > 0)
      {
          int nRead = read4(buf);
          buf += nRead;
          n -= nRead;
          res += nRead;
          // 可读数据小于4，则可提前结束
          if (nRead < 4)
          {
              break;
          }
      }
      
      return res;
  }
};
