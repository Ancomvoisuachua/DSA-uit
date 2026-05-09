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

bool Search(TreeNode* root, int val) {
    if (!root) return false;

    if (val == root->val) return true;
    else if (root->val < val) return Search(root->right, val);
    else return Search(root->left, val);
}

int main() {
    int n, t;
    cin >> n >> t;

    TreeNode* root = nullptr;
    while (n--) {
        int x;
        cin >> x;

        root = Insert(root, x);
    }
    
    while (t--) {
        int x1;
        cin >> x1;

        if (Search(root, x1)) cout << "YES \n";
        else cout << "NO \n";
    }

    return 0;
}