#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int x) {
    if (root == nullptr)
        return new Node(x);

    if (x < root->val)
        root->left = insert(root->left, x);
    else if (x > root->val)
        root->right = insert(root->right, x);

    return root;
}

void findPreSuc(Node* root, int x, int& pre, int& suc, bool& hasPre, bool& hasSuc) {
    while (root) {
        if (x < root->val) {
            suc = root->val;
            hasSuc = true;
            root = root->left;
        }
        else if (x > root->val) {
            pre = root->val;
            hasPre = true;
            root = root->right;
        }
        else {
            Node* temp = root->left;
            while (temp) {
                pre = temp->val;
                hasPre = true;
                temp = temp->right;
            }

            temp = root->right;
            while (temp) {
                suc = temp->val;
                hasSuc = true;
                temp = temp->left;
            }

            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    while (q--) {
        int x;
        cin >> x;

        int pre = 0, suc = 0;
        bool hasPre = false, hasSuc = false;

        findPreSuc(root, x, pre, suc, hasPre, hasSuc);

        if (hasPre) cout << pre;
        else cout << "NONE";

        cout << " ";

        if (hasSuc) cout << suc;
        else cout << "NONE";

        cout << '\n';
    }

    return 0;
}