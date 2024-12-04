// i. Find Median from Data Stream

#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> leftHeap; // Max-heap
    priority_queue<int, vector<int>, greater<int>> rightHeap; // Min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        // Add the number to the appropriate heap
        if (leftHeap.empty() || num <= leftHeap.top()) {
            leftHeap.push(num);
        } else {
            rightHeap.push(num);
        }

        // Balance the heaps so that their sizes differ by at most 1
        if (leftHeap.size() > rightHeap.size() + 1) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        } else if (rightHeap.size() > leftHeap.size()) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }

    double findMedian() {
        // If the total number of elements is odd, the median is the top of the larger heap
        if (leftHeap.size() > rightHeap.size()) {
            return leftHeap.top();
        }
        // If the total number of elements is even, the median is the average of the two tops
        return (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};




// ******************************************************************



// ii. Kth Largest Element in a Stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > K)
            pq.pop();
        
        return pq.top();
    }
};