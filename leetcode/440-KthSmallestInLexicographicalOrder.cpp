#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// This is a hard counting problem.
// https://discuss.leetcode.com/topic/64624/concise-easy-to-understand-java-5ms-solution-with-explaination
//
// Count nodes in a denary tree
class Solution {
public:
    int findKthNumber(int n, int k) {
        int num = 1;
        --k;
        while (k > 0) {
            int count = 0;
            for (long long first = num, last = num+1; first <= n; first *= 10, last *= 10)
                count += min(n+1LL, last) - first;
            if (count <= k) {
                k -= count;
                num++;
            } else {
                k--;
                num *= 10;
            }
        }
        return num;
    }
};


int main() {
    Solution s;
    cout << s.findKthNumber(INT_MAX, 100) << endl;
    return 0;
}
