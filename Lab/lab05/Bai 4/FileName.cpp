#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

void Init(List& l) {
	l.head = nullptr;
	l.tail = nullptr;
}

Node* CreateNode(int x) {
	Node* p = new Node;
	p->val = x;
	p->next = nullptr;
	return p;
}

void Push(List& l, int x) {
	Node* p = CreateNode(x);

	if (!l.head) 
		l.head = l.tail = p;
	else {
		l.tail->next = p;
		l.tail = l.tail->next;
	}
}

void RemoveK(List& l, int k) {
	Node dummy;
	dummy.next = l.head;

	Node* prev = &dummy;
	Node* cur = l.head;

	while (cur) {
		if (cur->val == k) {
			prev->next = cur->next;

			if (cur == l.tail)
				l.tail = prev == &dummy ? nullptr : prev;

			Node* temp = cur;
			cur = cur->next;

			delete temp;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}

	l.head = dummy.next;
}

void Print(List& l) {
	Node* cur = l.head;
	while (cur) {
		cout << cur->val<< " ";
		cur = cur->next;
	}
}

int main() {
	int n;
	cin >> n;

	List l;
	Init(l);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		Push(l, x);
	}

	int k;
	cin >> k;
	RemoveK(l, k);

	Print(l);

	return 0;
}