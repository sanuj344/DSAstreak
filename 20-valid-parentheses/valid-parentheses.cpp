class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            // agar opening bracket hai
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                // closing bracket aaya but stack empty hai
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // matching check
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // agar stack empty hai to valid
        return st.empty();
    }
};
