// An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

// a) it                      --> it    (no abbreviation)

//      1
// b) d|o|g                   --> d1g

//               1    1  1
//      1---5----0----5--8
// c) i|nternationalizatio|n  --> i18n

//               1
//      1---5----0
// d) l|ocalizatio|n          --> l10n
// Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

// Example: 

// Given dictionary = [ "deer", "door", "cake", "card" ]

// isUnique("dear") -> false
// isUnique("cart") -> true
// isUnique("cane") -> false
// isUnique("make") -> true
 

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto a : dictionary) 
        {
            string k = a[0] + to_string(a.size() - 2) + a.back();
            m[k].insert(a);
        }
    }
    // 1. dictionary = {"dear"},         isUnique("door") -> false
    // 2. dictionary = {"door", "door"}, isUnique("door") -> true
    // 3. dictionary = {"dear", "door"}, isUnique("door") -> false
    bool isUnique(string word) {
        string k = word[0] + to_string(word.size() - 2) + word.back();
        return m[k].count(word) == m[k].size();
    }
private:
    unordered_map<string, set<string>> m; // 需要记录相同缩写的单词
};