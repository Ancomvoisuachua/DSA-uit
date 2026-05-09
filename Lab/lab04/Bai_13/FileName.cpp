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

int Height(TreeNode* root) {
    if (!root) return -1;
    return 1 + max(Height(root->left), Height(root->right));
}

bool Check(TreeNode* root) {
    if (!root) return true;

    int left = Height(root->left);
    int right = Height(root->right);

    if (abs(left - right) > 1) return false;

    return Check(root->left) && Check(root->right);
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

    if (Check(root)) cout << "BALANCED";
    else cout << "NOT BALANCED";
    return 0;
}