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

// All O(n) solutions will get TLE


// Solution 1 : divide and conquer 1, O((logn)^2)
class Solution {
public:
    int countNodes(TreeNode* root) {
        int lh = 0, rh = 0;
        for (TreeNode* p = root; p; p = p->left) ++lh;
        for (TreeNode* p = root; p; p = p->right) ++rh;
        if (lh == rh) return (1<<lh) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


// Solution 2 : divide and conquer 2, O((logn)^2)
class Solution_2 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int h = 0, rh = 0;
        for (TreeNode* p = root; p; p = p->left) ++h;
        for (TreeNode* p = root->right; p; p = p->left) ++rh;
        if (h == rh+1) return 1 + (1<<rh)-1 + countNodes(root->right);
        else return 1 + countNodes(root->left) + (1<<rh)-1;
    }
};


// Solution 3 : count the lowest level's nodes only, the fastest, O(h^2), 72ms
// first check the right most child of the current node's left child.
// If this child exists, we know that there may be more nodes on the right side of the tree.
// So we move the current node to it's right child. And repeat until we reach the lowest level.
class Solution_3 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int height = 0;
        for (TreeNode* p = root; p; p = p->left) ++height;
        int count = 0;
        TreeNode* p = root;
        int level = height - 2;
        while (level >= 0) {
            TreeNode* left = p->left;
            for (int i = 0; i < level; ++i) left = left->right;
            if (left) {
                p = p->right;
                count += (1 << level);
            }
            else p = p->left;
            --level;
        }
        if (p) ++count;
        return (1 << (height-1)) - 1 + count;
    }
};


int main() {
    return 0;
}
