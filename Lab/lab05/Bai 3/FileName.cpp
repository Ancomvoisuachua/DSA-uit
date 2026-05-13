#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int q;
	cin >> q;

	stack<int> stin;
	stack<int> stout;

	while (q--) {
		string s;
		cin >> s;

		if (s == "PUSH") {
			int x;
			cin >> x;
			stin.push(x);
		}
		else if (s == "POP") {
			if (stout.empty()) {
				while (!stin.empty()) {
					stout.push(stin.top());
					stin.pop();
				}
			}

			if (stout.empty()) 
				cout << "EMPTY \n";
			else {
				cout << stout.top() << '\n';
				stout.pop();
			}
		}
		else if (s == "FRONT") {
			if (stout.empty()) {
				while (!stin.empty()) {
					stout.push(stin.top());
					stin.pop();
				}
			}

			if (stout.empty()) 
				cout << "EMPTY \n";
			else 
				cout << stout.top() << '\n';
		}
	}
	return 0;
}