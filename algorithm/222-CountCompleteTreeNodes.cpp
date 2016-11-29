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

// Solution 1 : check if it is a perfect tree recursively, O((logn)^2)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = 0, rightHeight = 0;
        for (TreeNode* p = root; p; p = p->left) ++leftHeight;
        for (TreeNode* p = root; p; p = p->right) ++rightHeight;
        if (leftHeight == rightHeight) return (1 << leftHeight) - 1; // it's a perfect tree
        else return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


// Solution 2 : divide and conquer with max height, O((logn)^2)
class Solution_2 {
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h == 0)  return 0;
        if (height(root->right) == h-1) return (1<<(h-1))-1+1 + countNodes(root->right); // left subtree is a perfect tree, with height h-1
        else return countNodes(root->left) + (1<<(h-2))-1+1; // right subtree is a perfect tree, with height h-2
    }

    int height(TreeNode* root) {
        if (!root) return 0;
        return height(root->left) + 1;
    }
};


// Solution 3 : binary search, the fastest, O(h^2), 72ms
// first check the right most child of the current node's left child. If this child is exist, we know that there may be more nodes on the right side of the tree. So we move the current node to it's right child. And repeat until we reach the lowest level.
class Solution_3 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int height = 0;
        for (TreeNode* p = root; p; p = p->left) ++height;
        int level = height - 2;
        int count = 0;
        TreeNode* p = root;
        while (level >= 0) {
            TreeNode* left = p->left;
            for (int i = 0; i < level; ++i) left = left->right;
            if (left) {
                p = p->right;
                count += (1 << level);
            }
            else
                p = p->left;
            --level;
        }
        if (p) ++count;
        return (1 << (height-1)) - 1 + count;
    }
};

int main() {
    Solution s;
    return 0;
}

