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

TreeNode* Min_BST(TreeNode* root) {
    while (root->left)
        root = root->left;

    return root;
}


TreeNode* Insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val == root->val) return root;
    else if (root->val < val) root->right = Insert(root->right, val);
    else root->left = Insert(root->left, val);

    return root;
}

TreeNode* Remove(TreeNode* root, int val) {
    if (!root) return nullptr;

    if (root->val == val) {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        else {
            TreeNode* temp = Min_BST(root->right);
            root->val = temp->val;
            root->right = Remove(root->right, temp->val);
        }
    }
    else if (root->val < val)
        root->right = Remove(root->right, val);
    else
        root->left = Remove(root->left, val);

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
    
    int k;
    cin >> k;
    root = Remove(root, k);
    Inorder(root);
    return 0;
}