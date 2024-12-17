// i. Maximum Score of a Good Subarray

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int i = k;
        int j = k;
        int curMin = nums[k];
        
        int result = nums[k];
        
        while(i > 0 || j < n-1) {
            int leftValue;
            int rightValue;
            
            if(i > 0) {
                leftValue = nums[i-1];
            } else {
                leftValue = 0;
            }
            
            if(j < n-1) {
                rightValue = nums[j+1];
            } else {
                rightValue = 0;
            }
            
            if(leftValue < rightValue) { 
                j++;
                curMin = min(curMin, nums[j]);
            } else {
                i--;
                curMin = min(curMin, nums[i]);
            }
            
            result = max(result, curMin * (j-i+1));
        }
        
        return result;
    }
};





// *****************************************************



// ii. Minimum Number of Increments on Subarrays to Form a Target Array

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        long long result = 0;

        int curr = 0;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            curr = target[i];

            if(abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }

            prev = curr;
        }

        return result;
    }
};
