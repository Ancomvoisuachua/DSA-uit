#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

void Delete_first_element(Node*& head) {
	if (head == nullptr) return;

	Node* temp = head;   
	head = head->next;   
	delete temp;         
}

int main() {
	int t;
	cin >> t;

	Node* head = nullptr;
	Node* tail = nullptr;

	while (t--) {
		int x;
		cin >> x;

		if (x == 0) return 0;
		else {
			Node* p = new Node(x);

			if (head == nullptr)
				head = tail = p;
			else {
				tail->next = p;
				tail = tail->next;
			}
		}
	}

	Delete_first_element(head);
	while (head) {
		cout << head->val;
		head = head->next;
	}
	return 0;
}