// i. Maximum Frequency Stack

class FreqStack {
    //max-heap
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> freq; 
    int pos = 0;
public:
    void push(int x) {
        pq.push(make_pair(++freq[x], make_pair(++pos, x)));
    }
    
    int pop() {
        auto val = pq.top();
        pq.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

// **************************************

// ii. Min Stack

class MinStack {
    int stack[10000];
    int min[10000];
    int topPtr;
    int minPtr;
public:
    
    MinStack() {
        topPtr = -1;
        minPtr = -1;
    }
    
    void push(int x) {
        if(topPtr >= 10000)
            return;
        
        stack[++topPtr] = x;
        
        if(minPtr >= 0)
        {
            if(min[minPtr] > x)
                min[++minPtr] = x;
            else
            {
                min[minPtr+1] = min[minPtr];
                minPtr += 1;
            }
        }
        else
            min[++minPtr] = x;
                
    }
    
    void pop() {
        if(topPtr < 0)      //Underflow
            return;
        
        topPtr -= 1;
        minPtr -= 1;
    }
    
    int top() {        
        return stack[topPtr];
    }
    
    int getMin() {
        return min[minPtr];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
