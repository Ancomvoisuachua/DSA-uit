#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

void Split_List(Node* A, Node*& B, Node*& C) {
    if (A == NULL) {
        B = C = NULL;
        return;
    }

    Node* slow = A;
    Node* fast = A;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    B = A;
    C = slow->next;
    slow->next = nullptr;
}

void Print_List(Node* head) {
    while (head) {
        cout << head->val;
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;
    Node* B = nullptr;
    Node* C = nullptr;

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
    Split_List(head, B, C);

    Print_List(B);
    cout << endl;

    Print_List(C);
    return 0;
}