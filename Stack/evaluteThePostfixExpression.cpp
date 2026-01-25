#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

bool isNumber(const string& s) {
    if (s.empty()) return false;
    int start = (s[0] == '-') ? 1 : 0;
    for (int i = start; i < (int)s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    if (!fin) {
        cerr << "Input file error\n";
        return 1;
    }

    stack<int> st;
    string token;

    while (fin >> token) {
        if (isNumber(token)) {
            st.push(stoi(token));
        } 
        else {
            if (st.size() < 2) {
                fout << "Invalid postfix expression\n";
                return 0;
            }

            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (token == "+") st.push(b + a);
            else if (token == "-") st.push(b - a);
            else if (token == "*") st.push(b * a);
            else if (token == "/") {
                if (a == 0) {
                    fout << "Division by zero\n";
                    return 0;
                }
                st.push(b / a);
            }
            else {
                fout << "Unknown operator\n";
                return 0;
            }
        }
    }

    if (st.size() != 1)
        fout << "Invalid postfix expression\n";
    else
        fout << st.top() << '\n';

    return 0;
}