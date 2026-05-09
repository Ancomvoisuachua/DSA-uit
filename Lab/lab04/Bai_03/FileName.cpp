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

void Path(TreeNode* root, int x) {
    bool found = false;

    while (root) {
        cout << root->val;
        if (root->val == x)
            return;
        cout << " ";
        if (x < root->val) root = root->left;
        else root = root->right;
    }
    if (!found) cout << "NOT FOUND";
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
    Path(root, k);

    return 0;
}