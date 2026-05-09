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

bool Search(TreeNode* root, int x) {
    if (!root) return false;

    if (root->val == x) return true;
    if (x < root->val) return Search(root->left, x);
    return Search(root->right, x);
}

void LCA(TreeNode* root, int x, int y) {
    if (!root) return;

    if (x < root->val && y < root->val) LCA(root->left, x, y);
    else if (x > root->val && y > root->val) LCA(root->right, x, y);
    else cout << root->val;
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
    
    int x, y;
    cin >> x >> y;
    if (!Search(root, x) || !Search(root, y)) cout << "NOT FOUND";
    else LCA(root, x, y);

    return 0;
}