#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

void Ascending_Order(Node*& head, int k) {
    Node* newNode = new Node(k);

    if (!head || head->val > k) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->val < k) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
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
    int k;
    cin >> k;
    Ascending_Order(head, k);
    while (head) {
        cout << head->val;
        head = head->next;
    }
    return 0;
}