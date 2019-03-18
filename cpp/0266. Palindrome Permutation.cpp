// Given a string, determine if a permutation of the string could form a palindrome.

// For example,
// "code" -> False, "aab" -> True, "carerac" -> True.

// Hint:

// Consider the palindromes of odd vs even length. What difference do you notice?
// Count the frequency of each character.
// If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?


class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> t;

        for (auto a : s) 
        {
            if (t.find(a) == t.end()) 
                t.insert(a);
            else 
                t.erase(a);
        }

        return t.size() <= 1;
    }
};