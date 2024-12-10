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

class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening=0;   // Counts unmatched opening parentheses '('
        int overbalanced_closing=0;   // Counts unmatched closing parentheses ')'
        for(int i=0; s[i]!='\0'; ++i){
            if(s[i]=='(') {
                opening++;   // Increment for each opening '('
            }
            else if(opening>0) {
                opening--;   // Valid closing ')' that balances an unmatched '('
            }
            else {
                overbalanced_closing++;   // A closing ')' without a corresponding '('
            }
        }
        return opening + overbalanced_closing;   // Total unmatched '(' and ')' need to be added
    }
};