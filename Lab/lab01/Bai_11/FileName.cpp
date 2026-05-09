#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

void Delete_last_element(Node& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
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
    Delete_last_element(head);
    while (head) {
        cout << head->val;
        head = head->next;
    }
    return 0;
}