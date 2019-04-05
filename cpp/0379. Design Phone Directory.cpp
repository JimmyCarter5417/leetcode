// Design a Phone Directory which supports the following operations:

 

// get: Provide a number which is not assigned to anyone.
// check: Check if a number is available or not.
// release: Recycle or release a number.
// Example:

// // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
// PhoneDirectory directory = new PhoneDirectory(3);

// // It can return any available phone number. Here we assume it returns 0.
// directory.get();

// // Assume it returns 1.
// directory.get();

// // The number 2 is available, so return true.
// directory.check(2);

// // It returns 2, the only number that is left.
// directory.get();

// // The number 2 is no longer available, so return false.
// directory.check(2);

// // Release number 2 back to the pool.
// directory.release(2);

// // Number 2 is available again, return true.
// directory.check(2);


class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        max_num = maxNumbers;
        next = idx = 0;
        recycle.resize(max_num);
        flag.resize(max_num, 1);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next == max_num && idx <= 0) return -1;
        if (idx > 0) {
            int t = recycle[--idx];
            flag[t] = 0;
            return t;
        }
        flag[next] = false;
        return next++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return number >= 0 && number < max_num && flag[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < max_num && !flag[number]) {
            recycle[idx++] = number;
            flag[number] = 1;
        }
    }
private:
    int max_num, next, idx;
    vector<int> recycle, flag;
};