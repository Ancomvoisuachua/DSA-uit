#include <iostream>
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

int One_child(TreeNode* root) {
    if (!root) return 0;

    int cnt = 0;
    if ((root->left && !root->right) ||
        (!root->left && root->right))
        cnt = 1;

    return cnt + One_child(root->left)
        + One_child(root->right);
}

int Two_children(TreeNode* root) {
    if (!root) return 0;

    int cnt = 0;
    if (root->left && root->right) cnt = 1;

    return cnt + Two_children(root->left) + Two_children(root->right);
}

int Only_left(TreeNode* root) {
    if (!root) return 0;

    int cnt = 0;
    if (root->left && !root->right) cnt = 1;

    return cnt + Only_left(root->left) + Only_left(root->right);
}

int Only_right(TreeNode* root) {
    if (!root) return 0;

    int cnt = 0;
    if (!root->left && root->right) cnt = 1;

    return cnt + Only_right(root->left) + Only_right(root->right);
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
    cout << One_child(root) << " " << Two_children(root) << " " << Only_left(root) << " " << Only_right(root);
    return 0;
}