// 1. Search a 2D Matrix

// This code checks if a number (target) is in a 2D grid (matrix) using Binary Search.
// Binary Search is a way to search quickly by dividing the search range in half each time.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows in the matrix (m) and number of columns (n).
        int m = matrix.size();         // Total number of rows.
        int n = matrix[0].size();      // Total number of columns.

        // Treat the 2D grid as if it’s one long list for easier searching.
        int start = 0;                 // The first position in the list (start of search).
        int end = m * n - 1;           // The last position in the list (end of search).

        // While there are still positions to check between start and end:
        while (start <= end) {
            // Find the middle position between start and end.
            int mid = start + (end - start) / 2;

            // Figure out the row and column of this middle position in the 2D grid.
            int row = mid / n;         // Row = divide by number of columns.
            int col = mid % n;         // Column = remainder when divided by number of columns.

            // Check if the value at this position is bigger, smaller, or equal to the target.
            if (matrix[row][col] > target) {
                // If the middle value is too big, move the search to the left half.
                end = mid - 1;
            } else if (matrix[row][col] < target) {
                // If the middle value is too small, move the search to the right half.
                start = mid + 1;
            } else {
                // If the value matches the target, return true (we found it!).
                return true;
            }
        }

        // If we finish the search and didn’t find the target, return false.
        return false;
    }
};

// *******************************************************************

// 2. Search in Rotated Sorted Array II

class Solution {
public:
    // This function finds the pivot (the smallest element in a rotated array).
    // A rotated array means the original order is shifted, like [4, 5, 6, 1, 2, 3].
    int pivot(vector<int>& nums, int l, int r) {
        // Keep checking until the left pointer meets the right pointer.
        while (l < r) {
            
            // Skip duplicate numbers from the left to avoid confusion.
            while (l < r && nums[l] == nums[l+1])
                l++;
            
            // Skip duplicate numbers from the right to avoid confusion.
            while (l < r && nums[r] == nums[r-1])
                r--;
            
            /*
                Why skip duplicates? Let's say you have a lot of the same numbers in a row,
                like [1, 1, 1, 1, 2, 1]. If we don't ignore duplicates, 
                the search might make mistakes about where the smallest number (pivot) is.
                This is very important for tricky cases like finding the smallest
                number in rotated arrays with duplicates!
            */
            
            // Find the middle of the current section.
            int mid = l + (r - l) / 2;
            
            // If the middle number is less than or equal to the rightmost number, 
            // this means the smallest part is on the left or it could be the middle itself.
            if (nums[mid] <= nums[r]) { // sorted part
                r = mid; // Move the right pointer to the middle.
            } else {
                // Otherwise, the smallest number must be on the right side.
                l = mid + 1;
            }
        }
        
        // The right pointer ends up at the pivot (the smallest number).
        return r;
    }
    
    // This function does a Binary Search, which is like guessing a number 
    // but cutting the choices in half every time.
    bool binarySearch(vector<int>& nums, int l, int r, int& target) {
        // Keep searching while the left pointer is less than or equal to the right pointer.
        while (l <= r) {
            // Find the middle of the section we're searching.
            int mid = l + (r - l) / 2;
            
            // If the number in the middle is what we're looking for, we're done!
            if (nums[mid] == target)
                return true;
            
            // If the target number is bigger, look at the right side.
            if (nums[mid] < target)
                l = mid + 1;
            else
                // If the target number is smaller, look at the left side.
                r = mid - 1;
        }
        
        // If we didn't find the number, return false.
        return false;
    }
    
    // This function checks if the target number is in the rotated array.
    bool search(vector<int>& nums, int target) {
        int n = nums.size(); // Find out how many numbers are in the array.
        
        // First, find the pivot (the smallest number in the array).
        int p = pivot(nums, 0, n - 1);
        cout << "p = " << p << endl; // Debugging: Show the pivot index.
        
        // Try searching in the left part (from the start to one before the pivot).
        if (binarySearch(nums, 0, p - 1, target)) {
            return true;
        }
        
        // If not found, search in the right part (from the pivot to the end).
        return binarySearch(nums, p, n - 1, target);
    }
};
