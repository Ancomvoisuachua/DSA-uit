#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

void Create_List(Node*& head, int n) {
    Node* tail = nullptr;
    while (n--) {
        int x;
        cin >> x;
        Node* p = new Node(x);
        if (head == nullptr)
            head = tail = p;
        else {
            tail->next = p;
            tail = tail->next;
        }
    }
}

void Print_List(Node* head) {
    while (head) {
        cout << head->val;
        head = head->next;
    }
}

Node* Merge_list(Node* A, Node* B) {
    if (A == nullptr) return B;

    Node* temp = A;
    while (temp->next)
        temp = temp->next;
    temp->next = B;
    return A;
}

int main() {
    int n;
    cin >> n;

    Node* A = nullptr;
    Create_List(A, n);

    Node* B = nullptr;
    Create_List(B, n);

    Node* C = Merge_list(A, B);
    Print_List(C);
    return 0;
}