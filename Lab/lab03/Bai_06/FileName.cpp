#include<iostream> 
#include<stack>
#include<string>
#include<cctype>
using namespace std;

int Char_to_Val(char n) {
    if (isdigit(n)) return n - '0';
    else return toupper(n) - 'A' + 10;
}

string Decimal_to_B(long long a, int b) {
    if (a == 0) return "0";
    stack<int> c;
    while (a > 0) {
        int temp = a % b;
        c.push(temp);
        a /= b;
    }
    string result = "";
    while (!c.empty()) {
        int val = c.top(); c.pop();
        if (val < 10) result += char(val + '0');
        else result += char(val - 10 + 'A');
    }
    return result;
}

string N_to_Decimal(string n, int a, int b) {
    long long Pow = 1;
    long long rs = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
        rs += Char_to_Val(n[i]) * Pow;
        Pow *= a;
    }
    return Decimal_to_B(rs, b);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string N;
        int A, B;
        cin >> N >> A >> B;
        cout << N_to_Decimal(N, A, B) << endl;
    }
    return 0;
}