// i. First non-repeating in a stream





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
