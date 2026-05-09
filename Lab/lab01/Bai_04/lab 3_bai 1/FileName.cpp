#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
};
typedef struct Node* node;

node Reverse(node head) {
	node prev = nullptr;
	node curr = head;

	while (curr != nullptr) {
		node next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}
int main()
{
	int n;
	cin >> n;

	node head = nullptr;
	node tail = nullptr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		node p = new Node(x);
		if (head == nullptr)
			head = tail = p;
		else {
			tail->next = p;
			tail = tail->next;
		}
	}

	head = Reverse(head);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}