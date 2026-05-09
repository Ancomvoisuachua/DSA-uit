#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* Insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val == root->val) return root;
    else if (root->val < val) root->right = Insert(root->right, val);
    else root->left = Insert(root->left, val);

    return root;
}

int Min_BST(TreeNode* root) {
    while (root->left)
        root = root->left;

    return root->val;
}

int Max_BST(TreeNode* root) {
    while (root->right)
        root = root->right;

    return root->val;
}

int SecondLargest(TreeNode* root) {
    TreeNode* cur = root;
    TreeNode* parent = nullptr;

    while (cur->right) {
        parent = cur;
        cur = cur->right;
    }

    if (cur->left) {
        cur = cur->left;

        while (cur->right)
            cur = cur->right;

        return cur->val;
    }

    return parent->val;
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;
    while (n--) {
        int x;
        cin >> x;

        root = Insert(root, x);
    }
    cout << Min_BST(root) << " " << Max_BST(root) << " " << SecondLargest(root);
    return 0;
}