#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};

void Reverse(Node*& head) {
	stack<int> st;
	Node* p = head;

	while (p != nullptr) {
		st.push(p->val);
		p = p->next;
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
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

	Reverse(head);
	return 0;
}