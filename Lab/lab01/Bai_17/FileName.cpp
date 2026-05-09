#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next = nullptr;
	Node(int x) : val(x), next(nullptr){}
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

Node* Merge_two_List(Node* A, Node* B) {
	Node* dummy = new Node(0);
	Node* tail = dummy;
	while (A && B) {
		if (A->val > B->val) {
			tail->next = B;
			B = B->next;
		}
		else {
			tail->next = A;
			A = A->next;
		}
		tail = tail->next;
	}
	if (A) tail->next = A;
	else tail->next = B;

	return dummy->next;
}

void Print_List(Node* head) {
	while (head) {
		cout << head->val;
		head = head->next;
	}
}

int main() {
	int n1, n2;

	cin >> n1;
	Node* A = nullptr;
	Create_List(A, n1);

	cin >> n2;
	Node* B = nullptr;
	Create_List(B, n2);

	Node* C = Merge_two_List(A, B);
	Print_List(C);
}