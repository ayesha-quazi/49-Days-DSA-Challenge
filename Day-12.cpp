// i. Longest Valid Parentheses

class Solution {
public:
    // This function finds the longest sequence of matching parentheses.
    int longestValidParentheses(string s) {
        
        // We use a "stack" to keep track of indices (positions in the string).
        stack<int> idx; 
        
        // 'ans' will store the length of the longest valid parentheses sequence.
        int ans = 0;
        
        // Push -1 onto the stack to handle the starting point of a valid sequence.
        idx.push(-1);
        
        // Loop through every character in the string.
        for(int i = 0; i < s.length(); ++i) {
            
            // If the character is '(', we push its position (index) onto the stack.
            if(s[i] == '(')
                idx.push(i);
            else {
                // If the character is ')', we first pop the top element of the stack.
                idx.pop();
                
                // If the stack is empty after popping, push the current index.
                // This means the previous sequence of parentheses has ended, 
                // so we start a new possible sequence from here.
                if(idx.size() == 0)
                    idx.push(i);
                else {
                    // If the stack is not empty, calculate the length of the 
                    // current valid sequence using the difference between 
                    // the current position and the position at the top of the stack.
                    ans = max(ans, i - idx.top());
                }
            }
        }
        
        // Finally, return the longest valid parentheses sequence length.
        return ans;
    }
};
 
// ***************************************************************************


// ii. Sum of Subarray Minimums


//Approach (Simple Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        long result = 0;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];

            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                result = (result + minVal) % M;
            }
        }

        return result;
    }
};

/*
    First see the code and video to understand, then read this paragraph.
    
    Explanation on why we have done "strictly less" in one case and "non-strictly less"
    in another. (They can be interchanged but both can't be non-strictly less)
    
    Ans : This it to avoid repeated inclusion of same subarray
          s . . . m1 . . . . . m2 . . . s’
          ....r1 ...... r2 ........ r3

Basically we have A[s] is the PLE of A[m1] (strictly less), and all the elements in-between
which I denote by r1 is greater than A[m1]. A[m1] == A[m2], and all elements in-between
which I denote by r2 are greater, and A[s'] is the NLE of A[m2] (strictly less), and again all
elements in-between which I denote by r3 are greater.

If we used the strictly less definition for both PLE and NLE, then A[s] and A[s'] are the PLE
and NLE for both A[m1] and A[m2]. m1 will count [r1, r2] and m2 will count [r2, r3], but
both will count [r1, r3]. To avoid this, notice our definition of NLE is less than or equal.
So that means NLE of A[m1] is A[m2]. This means [r1, r3] is only counted once.
*/


// ***************************************************************************

// iii. Insert Interval


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0])
                i++;
            else if (intervals[i][0] > newInterval[1]){
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);
            }
        }
        
        intervals.push_back(newInterval);
        return intervals;
    }
};

//Approach (TLE) 
//T.C : (O(n^2))
//S.C : O(1)



















// ***************************************************************************

