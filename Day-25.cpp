// i. Valid Parentheses:

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch:s) {
            if(st.empty() || ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }
            
            if(ch == ')') {
                if(st.top() == '(')
                    st.pop();
                else
                    return false;
            } else if(ch == '}') {
                if(st.top() == '{')
                    st.pop();
                else
                    return false;
            } else if(ch == ']') {
                if(st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};

// **************************************************************************

// ii. Maximum Nesting Depth of the Parentheses:

class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int openBrackets = 0;

        for (char &ch : s) {
            if (ch == '(') {
                openBrackets++;
            } else if (ch == ')') {
                openBrackets--;
            }
            
            result = max(result, openBrackets);
        }
        
        return result;
    }
};

// **************************************************************************

// iii. Minimum Add to Make Parentheses Valid: 

