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

void KthSmallest(TreeNode* root, int k, int& count) {
    if (!root) return;
    
    KthSmallest(root->left, k, count);
    
    count++;
    if (count == k) {
        cout << root->val;
        return;
    }

    KthSmallest(root->right, k, count);
}

int main() {
    int n, k;
    cin >> n >> k;

    TreeNode* root = nullptr;
    while (n--) {
        int x;
        cin >> x;

        root = Insert(root, x);
    }

    int count = 0;
    KthSmallest(root, k, count);

    return 0;
}