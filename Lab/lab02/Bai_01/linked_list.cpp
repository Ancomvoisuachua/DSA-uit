#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
};
typedef struct Node* node;

node creatNode(int x) {
	node p = new Node;
	p->val = x;
	p->next = nullptr;
	return p;
}
void append(node& a, int x) {
	node p = creatNode(x);
	if (!a) a = p;
	else {
		node current = a;
		while (current->next != nullptr) current = current->next;
		current->next = p;
	}
}
void input(node& a, int n) {
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		append(a, x);
	}
}
void output(node a) {
	while (a != nullptr) {
		cout << a->val << " ";
		a = a->next;
	}
	cout << endl;
}
node selectionSort(Node* a) {
	for (node i = a; i != nullptr; i = i->next) {
		node minNode = i;

		for (node j = i->next; j != nullptr; j = j->next) {
			if (j->val < minNode->val)
				minNode = j;
		}

		swap(i->val, minNode->val);
	}
	return a;
}
node interchangeSort(Node* a) {
	for (node i = a; i != nullptr; i = i->next) {
		for (node j = i->next; j != nullptr; j = j->next) {
			if (i->val > j->val) {
				swap(i->val, j->val);
			}
		}
	}
	return a;
}
node insertionSort(Node* a) {
	node sorted = nullptr;

	while (a) {
		node cur = a;
		a = a->next;

		if (!sorted || cur->val < sorted->val) {
			cur->next = sorted;
			sorted = cur;
		}
		else {
			node p = sorted;
			while (p->next && p->next->val < cur->val)
				p = p->next;

			cur->next = p->next;
			p->next = cur;
		}
	}
	return sorted;
}
int main() {
	node head = nullptr;
	int n;
	cin >> n;

	input(head, n);

	head = insertionSort(head);
	output(head);
	head = selectionSort(head);
	output(head);
	head = interchangeSort(head);
	output(head);
}