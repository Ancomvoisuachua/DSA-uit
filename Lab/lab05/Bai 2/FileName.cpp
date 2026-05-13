#include <iostream>
#include <string>
using namespace std;

void Binary(int pos, int n, string s) {
    if (pos == n) {
        cout << s << '\n';
        return;
    }

    s[pos] = '0';
    Binary(pos + 1, n, s);

    if (pos == 0 || s[pos - 1] != '1') {
        s[pos] = '1';
        Binary(pos + 1, n, s);
    }
}


int main() {
	int n;
	cin >> n;

	string s;
	s.resize(n);

    Binary(0, n, s);

    return 0;
}