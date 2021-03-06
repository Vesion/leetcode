#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/repeated-substring-pattern/


// Solution 1 : trivial, O(n^2)
class Solution_1 {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        for (int l = n/2; l >= 1; --l) {
            if (n%l != 0) continue;
            string p = str.substr(0, l);
            int i = l;
            while (i < n) {
                if (str.substr(i, l) == p) i += l;
                else break;
            }
            if (i == n) return true;
        }
        return false;
    }
};


// Solution 2 : KMP, O(n)
class Solution_2 {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        vector<int> prefix(n, 0);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j > 0 && str[i] != str[j]) j = prefix[j-1];
            if (str[i] == str[j]) ++j;
            prefix[i] = j;
        }
        return prefix[n-1] && (prefix[n-1] % (n-prefix[n-1]) == 0);
    }
};


// Solution 3 : an awesome solution! Orz
// https://discuss.leetcode.com/topic/68206/easy-python-solution-with-explaination
//
// Proof:
// https://discuss.leetcode.com/topic/72732/rigorous-proof-why-condition-s-s-find-s-1-s-size-is-equivalent-to-substring-repetition
//
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        return (str+str).find(str, 1) < str.size();
    }
};


int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("abcabc") <<endl;
    return 0;
}
