#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;

    int countUnivalSubtrees(TreeNode* root) {
        isUnival(root);
        return res;
    }

    bool isUnival(TreeNode* root) {
        if (!root) return true;
        bool left = isUnival(root->left), right = isUnival(root->right);
        if (left && right) {
            if (root->left && root->val != root->left->val) return false;
            if (root->right && root->val != root->right->val) return false;
            ++res;
            return true;

        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}
