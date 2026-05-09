#include <iostream>
#include <math.h>
#include <vector>
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

TreeNode* Input(TreeNode* root, int& n) {
    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        root = Insert(root, x);
    }
    return root;
}

void Inorder(TreeNode* root, vector<int>& temp) {
    if (!root) return;

    Inorder(root->left, temp);
    temp.push_back(root->val);
    Inorder(root->right, temp);
}

void Merge2BST(vector<int>& a, vector<int>& b, vector<int>& ans) {
    int i = 0, j = 0;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }

    while (i < a.size()) ans.push_back(a[i++]);
    while (j < b.size()) ans.push_back(b[j++]);
}

int main() {
    int n, n1;
    TreeNode* root = nullptr;
    TreeNode* root1 = nullptr;

    root = Input(root, n);
    root1 = Input(root1, n1);

    vector<int> a, b;
    Inorder(root, a);
    Inorder(root1, b);

    vector<int> ans;
    Merge2BST(a, b, ans);

    for (int i = 0; i < ans.size(); i++) {
        if (i == 0 || ans[i] != ans[i - 1])
            cout << ans[i] << " ";
    }

    return 0;
}