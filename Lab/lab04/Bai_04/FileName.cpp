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

int NumOfNode(TreeNode* root) {
    if (!root) return 0;
    return 1 + NumOfNode(root->left) + NumOfNode(root->right);
}

int NumOfLeaf(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return NumOfLeaf(root->left) + NumOfLeaf(root->right);
}

int NumOfInternal(TreeNode* root) {
    if (!root) return 0;
    if (root->left || root->right)
        return 1 + NumOfInternal(root->left) + NumOfInternal(root->right);
    return 0;
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
    cout << NumOfNode(root) << " " << NumOfLeaf(root) << " " << NumOfInternal(root);
    return 0;
}