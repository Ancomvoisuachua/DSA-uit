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

void Query(TreeNode* root, int l, int r, int& sum) {
    if (!root) return;

    if (root->val > l) Query(root->left, l, r, sum);

    if (l <= root->val && root->val <= r) {
        cout << root->val << " ";
        sum += root->val;
    }

    if (root->val < r) Query(root->right, l, r, sum);
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

    int l, r, sum = 0;
    cin >> l >> r;

    if (l <= r) {
        Query(root, l, r, sum);
        cout << "\n";
    }
    else cout << "INVALID";

    cout << sum;
    return 0;
}