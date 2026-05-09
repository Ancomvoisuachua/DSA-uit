#include <iostream>
#include <math.h>
#include <queue>
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

void PrintLevel(TreeNode* root, int level) {
    if (!root) return;

    if (level == 0) {
        cout << root->val << " ";
        return;
    }

    PrintLevel(root->left, level - 1);
    PrintLevel(root->right, level - 1);
}

void LevelOrder(TreeNode* root) {
    int h = Height(root);
    for (int i = 0; i <= h; i++) {
        PrintLevel(root, i);
        cout << '\n';
    }
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
    LevelOrder(root);
    return 0;
}