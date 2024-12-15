// i. Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge; // Map to store next greater elements
        stack<int> s;

        // Build the map for nums2
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nge[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        // For remaining elements in the stack, there is no next greater element
        while (!s.empty()) {
            nge[s.top()] = -1;
            s.pop();
        }

        // Prepare the result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nge[num]);
        }

        return result;
    }
};

// ****************************************

// ii. Final Prices With a Special Discount in a Shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res = prices; // Copy the prices array to res
        stack<int> s; // Stack to maintain indices

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && prices[i] <= prices[s.top()]) {
                int j = s.top();
                s.pop();
                res[j] = prices[j] - prices[i]; // Update the result for index j
            }
            s.push(i); // Push the current index onto the stack
        }

        return res; // Return the final discounted prices
    }
};
