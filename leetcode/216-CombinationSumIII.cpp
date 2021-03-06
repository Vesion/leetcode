#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(1, k, n, path);
        return res;
    }

    void dfs(int start, int k, int target, vector<int>& path) {
        if (k == 0) {
            if (target == 0) res.push_back(path);
            return;
        }
        for (int i = start; i <= 9; ++i) {
            if (target-i < 0) break;
            path.push_back(i);
            dfs(i+1, k-1, target-i, path);
            path.pop_back();
        }
    }
};


int main() {
    Solution s;
    auto r = s.combinationSum3(3, 9);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}

