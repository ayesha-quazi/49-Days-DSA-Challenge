// i. Frequency of the Most Frequent Element 


// This code is solving a problem where we want to find the maximum number of times
// we can make all numbers in a group equal, by adding up to "k" to any of the numbers.

// Here I've used the "sliding window" approach to solve the problem efficiently.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Step 1: Sort the numbers in ascending order
        // Sorting helps us group numbers and make them equal step by step.
        sort(begin(nums), end(nums));
        
        int n = nums.size(); // How many numbers are there in the input?
        int result = 0;      // This will store the maximum frequency (answer).
        int i = 0;           // Start of our "window" of numbers.
        long currSum = 0;    // This is the sum of the numbers in the current "window".
        
        // Step 2: Slide the "window" over the sorted numbers.
        for (int j = 0; j < n; j++) {
            long target = nums[j]; // The number we want to make all others equal to.
            currSum += nums[j];    // Add the current number to the sum.
            
            // Step 3: Check if making all numbers in the window equal to "target" is too expensive.
            // If the cost is greater than "k", shrink the window by moving its start (i) forward.
            while ((j - i + 1) * target - currSum > k) {
                currSum -= nums[i]; // Remove the number at the start of the window from the sum.
                i++;                // Move the start of the window to the right.
            }
            
            // Step 4: Update the result if the current window is larger than before.
            result = max(result, j - i + 1);
        }
        
        // Return the maximum number of times we can make all numbers in a group equal.
        return result;
    }
};

// Time Complexity (T.C): O(nlogn) -> Sorting the numbers takes O(nlogn), 
// and the sliding window part takes O(n).
// Space Complexity (S.C): O(1) -> We are not using any extra memory that grows with input size.


// ii. Subarrays with K Different Integers

// Approach: Using Sliding Window Technique (Two Times)
// This is a clever way to solve problems with "subarrays" (small parts of an array).
// We count the subarrays with up to K distinct numbers and subtract those with up to K-1 distinct numbers.
// Time Complexity (T.C): O(n) - the code runs in proportion to the size of the input.
// Space Complexity (S.C): O(n) - we use extra space to store some data temporarily.

class Solution {
public:
    // This function finds the total number of subarrays with "at most K distinct numbers."
    int slidingWindow(vector<int>& nums, int k) {
        // This map keeps track of how many times each number appears in the current window.
        unordered_map<int, int> mp;
        
        int n = nums.size(); // The size of the input array.
        int i = 0;           // The start of the sliding window.
        int j = 0;           // The end of the sliding window.
        int count = 0;       // This will store the total count of subarrays we find.

        // Move the end of the window (j) to explore more numbers.
        while (j < n) {
            // Add the number at the current position to our map.
            mp[nums[j]]++;
            
            // If the number of distinct numbers becomes greater than K, shrink the window.
            while (mp.size() > k) {
                // Remove the number at the start of the window from the map.
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    // If a number's count becomes 0, remove it completely from the map.
                    mp.erase(nums[i]);
                }
                i++; // Move the start of the window forward.
            }
            
            // Add all subarrays that end at the current position j.
            // (j - i + 1) gives the count of subarrays starting anywhere between i and j.
            count += (j - i + 1);
            
            // Move the end of the window forward.
            j++;
        }
        
        return count; // Return the total count of subarrays.
    }
    
    // Main function to find the subarrays with *exactly* K distinct numbers.
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Use our helper function twice:
        // 1. Count subarrays with at most K distinct numbers.
        // 2. Count subarrays with at most (K-1) distinct numbers.
        // Subtract the second result from the first to get subarrays with exactly K distinct numbers.
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};
