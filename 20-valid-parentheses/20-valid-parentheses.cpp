class Solution {
public:
    char transfer(char c) {
        char tc;
        switch (c) {
            case ')':
                tc = '(';
                break;
            case ']':
                tc = '[';
                break;
            case '}':
                tc = '{';
                break;
        }
        return tc;
    }
    
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
                st.push(s[i]);
            if (s.at(i) == ')' || s.at(i) == ']' || s.at(i) == '}') {
                if (st.empty()) return false;
                if (st.top() == transfer(s[i]))
                    st.pop();
                else
                    return false;
            }
        }
        if (!st.empty()) return false;
        else return true;
    }
};