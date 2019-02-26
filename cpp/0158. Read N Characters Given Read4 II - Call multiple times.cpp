// The API: int read4(char *buf) reads 4 characters at a time from a file.
// The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
// Note:
// The read function may be called multiple times.


int read4(buf);

class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) 
        {
            if (readPos == writePos) 
            {
                writePos = read4(buff); // 下一次写入的位置，即为当前的读取大小
                readPos = 0; // 每次read之后都要将readPos置零
                if (writePos == 0) // 读取大小为0，即可结束
                {
                    return i;
                }                    
            }
            
            buf[i] = buff[readPos++]; // 单个复制，写起来简单一些
        }
        
        return n;
    }
    
private:
    int readPos = 0, writePos = 0;
    char buff[4];
};
