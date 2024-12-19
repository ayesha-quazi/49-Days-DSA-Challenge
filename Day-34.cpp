// i. First non-repeating in a stream

#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string &s) {
        unordered_map<char, int> mm;
        queue<char> q;
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {  // Use 's' instead of 'A'
            mm[s[i]]++;
            if (mm[s[i]] == 1) q.push(s[i]);
            while (!q.empty() && mm[q.front()] > 1) q.pop();
            if (q.empty()) ans += '#';
            else ans += q.front();
        }
        return ans;
    }
};



// ***************************************************


// ii. Reverse First K elements of Queue

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        int remaining = q.size() - k; //2
        stack<int> st;
        while(k--) {
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        
        while(remaining--) {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
