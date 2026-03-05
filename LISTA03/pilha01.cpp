#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(const string &s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    string testes[] = { "()","()[]{}","(]","([])","([)]" };

    for (auto &s : testes) {
        cout << s << " -> " << (Solution().isValid(s) ? "true" : "false") << endl;
    }
    return 0;
}