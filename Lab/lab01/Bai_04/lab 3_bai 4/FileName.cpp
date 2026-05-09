#include <iostream>
#include <stack>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<double, int>> st;
    for (int i = 0; i < n; i++) {
        double coef;
        int exp;
        cin >> coef >> exp;
        st.push({ coef, exp });
    }

    double x;
    cin >> x;
    stack<pair<double, int>> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    cout << "Da thuc vua nhap la: ";

    bool hasTerm = false;
    double result = 0;

    while (!temp.empty()) {
        double coef = temp.top().first;
        int exp = temp.top().second;
        temp.pop();

        if (coef == 0) continue;
        if (hasTerm) {
            if (coef > 0) cout << "+";
        }
        if (exp == 0) {
            cout << coef;
        }
        else {
            if (coef == -1) cout << "-";
            else if (coef != 1) cout << coef;

            cout << "x";

            if (exp != 1) {
                cout << "^" << exp;
            }
        }
        hasTerm = true;

        result += coef * pow(x, exp);
    }

    if (!hasTerm) cout << "0";

    cout << endl;
    cout << "Voi x=" << x << ", gia tri da thuc la: ";
    cout << fixed << setprecision(2) << result;

    return 0;
}