# 49-Days DSA Challenge

Welcome to my 49-Day DSA journey! Over the next 49 days, I’ll be sharing my progress as I tackle challenging DSA problems in C++. These problems are part of the *Last Minute Revision* series provided by *Fraz Sir*. My goal is to solidify my understanding and apply key concepts daily.

<hr>

**Challenge Start Date:** 16th November 2024 <br>
**Language:** C++

<hr>

### Day 1
1. **3Sum** - Used a sorted array with a two-pointer approach to efficiently find unique triplets summing to zero, while skipping duplicates and handling edge cases.

<hr> 

### Day 2
2. **Sort Colors** - Applied a counting sort approach to efficiently sort an array with elements 0, 1, and 2. Key takeaway: prioritize simplicity for fixed-range problems.

3. **Next Permutation** - Unlocked the logic to find the next lexicographical permutation. The trick? Identify the pivot, swap strategically, and reverse the suffix.

<hr>

### Day 3

4. **Product of Array Except Self**- Efficiently computed products without division using left and right prefix products.

5. **Increment Submatrices by One** - Optimized range updates in a 2D grid with prefix sums to handle overlapping increments.

<hr>

### Day 4

6. **First Missing Positive** - Solved in linear time using in-place bucket sorting to handle the smallest missing positive integer.

7. **Count of Smaller Numbers After Self** - Leveraged binary indexed trees (BIT) or merge sort for an efficient count of smaller elements.

<hr>

### Day 5

8. Rotate Image: Here I've used matrix transposition and reversal to rotate a 2D array in place efficiently.

9. Spiral Matrix: And here used traverse a matrix layer by layer using controlled boundary variables.

<hr> 

### Day 6

10. Majority Element: Implemented the Boyer-Moore Voting Algorithm to efficiently find the majority element in linear time and constant space.

11. Subarray Sum Equals K: Used a prefix sum with a hashmap to count subarrays that sum up to a target value in O(n) time.

<hr> 

### Day 7

12. Reverse Linked List: Used iteration to reverse a linked list in-place, showcasing the importance of pointer manipulation in linked data structures.

13. Sort List: Applied merge sort on a linked list for efficient sorting with O(n log n) time complexity while managing space constraints.

<hr> 

### Day 8

14. Linked List Cycle II: Today implemented Floyd's Cycle Detection Algorithm to detect a cycle in the list. The approach uses two pointers, slow and fast, to determine the meeting point if a cycle exists. After detection, another pointer entry starts at the head to locate the cycle’s starting node by moving one step at a time\ along with slow.
TC: O(n)
SC: O(1)

15. Copy List with Random Pointer: Solved this question by first creating a new node for each original node using a hash map for O(n) space, then mapped the random pointers by referencing the hash map. This ensured that both the structure and random connections were accurately duplicated.
TC n SC: O(n)

<hr>

### Day 9 

16. My Calendar II: Solved using a sweep line algorithm with a map to manage start and end times of bookings. The key insight was maintaining a running count of active bookings and ensuring no point exceeds two simultaneous bookings.

17. Subarray Product Less Than K: Utilized a sliding window technique to count subarrays with a product less than k. Adjusted the window size dynamically by shrinking it when the product exceeded the threshold, ensuring efficiency.
