
#include <bits/stdc++.h>
using namespace std;

// Function to check if parentheses are valid
bool checkValidParentheses(const string& str) {
    stack<char> stk;

    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stk.empty()) return false;
            char top = stk.top(); stk.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stk.empty();
}

int main() {
    string str;
    getline(cin, str);

    if (checkValidParentheses(str)) {
        cout << "Valid Parentheses\n";
    } else {
        cout << "Invalid Parentheses\n";
    }

    return 0;
}
