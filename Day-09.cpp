// My Calendar II

class MyCalendarTwo {
    map<int, int> stops; // Keeps track of the changes at each timestamp (start or end of a booking)
public:
    MyCalendarTwo() {
        // Constructor initializes the class (no special setup needed)
    }
    
    bool book(int start, int end) {
        // Include the interval by default by marking a start and an end.
        // Increment at `start` (adding one booking starting here)
        // Decrement at `end` (removing one booking ending here)
        stops[start]++;
        stops[end]--;

        int booked = 0; // Keeps track of the number of overlapping bookings
        for (auto& stop : stops) { // Iterate through all recorded changes (sorted by time due to `map`)
            booked += stop.second; // Update the count of active bookings
            if (booked > 2) { // If there are more than 2 simultaneous bookings at any point:
                // Undo the changes we made for this booking attempt
                stops[start]--;
                stops[end]++;

                // Remove entries if their values become zero (no net effect left at these timestamps)
                if (stops[start] == 0)
                    stops.erase(start);
                if (stops[end] == 0)
                    stops.erase(end);

                return false; // Return false since the booking is invalid
            }
        }
        return true; // If no point had more than 2 overlaps, the booking is valid
    }
};




// Subarray Product Less Than K

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // If k is less than or equal to 1, no subarray product can be less than k.
        if(k <= 1)
            return 0;

        int n = nums.size(); // Get the size of the array.
        int count = 0;       // Variable to count the valid subarrays.
        
        int left = 0;        // Left pointer of the sliding window.
        int right = 0;       // Right pointer of the sliding window.
        int prod = 1;        // Variable to store the product of the current window.
        
        // Traverse the array using the right pointer.
        while(right < n) {
            prod *= nums[right]; // Multiply the current number into the product.
            
            // If the product becomes greater than or equal to k, shrink the window from the left.
            while(prod >= k) {
                prod /= nums[left]; // Remove the leftmost element from the product.
                left++;             // Move the left pointer to the right.
            }
            
            // Count all the subarrays that end at the current position (right).
            // This is calculated as the size of the current window: (right - left + 1).
            count += (right - left) + 1;
            
            // Expand the window by moving the right pointer.
            right++;
        }
        return count; // Return the total count of valid subarrays.
    }
};

/*
Approach: This is a standard sliding window problem. The goal is to maintain a window where the product of 
          its elements is less than `k`. If the product exceeds `k`, shrink the window from the left 
          until the product is valid again. For each position of the right pointer, count the valid subarrays 
          ending at that position.
          
Time Complexity (T.C): O(N), where N is the size of the input array, because we traverse the array once.
Space Complexity (S.C): O(1), as we use only a constant amount of extra space.
*/
