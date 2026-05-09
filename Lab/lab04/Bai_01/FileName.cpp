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

void Inorder(TreeNode* root) {
    if (!root) return;

    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
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
    
    Inorder(root);

    return 0;
}