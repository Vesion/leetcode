#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs.size();
        vector<vector<int>> dp = costs;
        for (int i = 1; i < n; ++i) {
            dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};


int main() {
    return 0;
}
