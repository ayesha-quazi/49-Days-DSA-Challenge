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

<hr>

### Day 10

18. Frequency of the Most Frequent Element: Applied a sliding window on a sorted array to maximize the frequency of an element within a window, adjusting when the cost exceeds k.
T.C: O(n log n) | S.C: O(1).

19. Subarrays with K Different Integers: Used sliding window with hash maps to count subarrays with exactly k distinct integers by finding the difference between subarrays with at most k and k-1.
T.C: O(n) | S.C: O(n).

<hr>

### Day 11

20. Merge k Sorted Lists: Solved using Divide & Conquer to merge pairs of lists recursively. Merged two lists using recursion based on their head node values. T.C: O(N log k) | S.C: O(log k) (recursive stack).

21. LRU Cache: Used a doubly linked list to maintain order of usage and a map to store values and positions. Keys are added to the front on access or insertion.
Evict the least recently used (tail of the list) if capacity is exceeded. T.C: O(1) for get() and put() | S.C: O(n).

22. LFU Cache: Organized keys by frequency using a map of lists and maintained their positions with an auxiliary unordered map. On access or insertion, moved items to higher frequency groups. Evicted the least frequently used item when full, prioritizing older items. T.C: O(1) for get() and O(log f) for put() | S.C: O(n).

<hr>

### Day 12

23. Longest Valid Parentheses: Used a stack to track indices and validate parentheses sequences. Push -1 initially to handle boundary cases. For each ), pop the stack and calculate the valid sequence length if the stack isn’t empty. Otherwise, reset with the current index.

24. Insert Interval: Calculated the minimum for every subarray and sum them up.

25. Sum of Subarray Minimums: raverse the list to find the correct position for insertion. Merge overlapping intervals by updating the start and end points of the newInterval. Insert the non-overlapping intervals in place.

<hr>

### Day 13 

26. Search a 2D Matrix: Treated the 2D matrix as a 1D array and used Binary Search to locate the target by calculating the row and column based on the midpoint.

27. Search in Rotated Sorted Array II: Got the pivot (smallest element) in the rotated array, then applied Binary Search on both parts of the array to find the target, handling duplicates during the process.

<hr>

### Day 14

28. Trapping Rain Water: Calculated trapped water using precomputed arrays for maximum heights to the left and right. For each bar, the trapped water = min(leftMax, rightMax) - height.

29. Largest Rectangle in Histogram: Used stacks to find nearest smaller bars on the left and right for each bar. Calculated the rectangle area for each bar and tracked the maximum.

<hr> 

### Day 15

30. Koko Eating Bananas: Used Binary Search to find the minimum eating speed that allows Koko to eat all bananas within h hours. Checked feasibility for each speed by simulating the total hours required.

31. Median of Two Sorted Arrays: Merged two sorted arrays into one sorted array and calculated the median. Handled odd and even combined lengths for precise median calculation.

<hr>

### Day 16

32. XOR Queries of a Subarray: Used a prefix XOR array to efficiently calculate XOR of any subarray in constant time. Pre-computed the cumulative XOR and answered multiple queries in O(1) time per query.

33. Gray Code: Generated Gray codes using recursion, where each Gray code is derived from the previous one with a bit-flip. Converted binary string results into integers.

34. Kth Smallest Number in Multiplication Table: Used Binary Search on the value range to find the k-th smallest number in the multiplication table. Counted how many numbers are less than or equal to the current mid value to adjust the search range.

<hr>

### Day 17

35. Find Longest Awesome Substring: Used a bitmask to track the odd/even counts of digits and their positions in the string. Checked for palindromic conditions by toggling bits (single odd digit allowed).

36. Shortest Subarray with Sum at Least K: Maintained a monotonic deque to track prefix sums and their indices. Removed unnecessary prefix sums to ensure the subarray sum satisfies >= k.

<hr>

### Day 18

37. The Skyline Problem: Transformed building edges into "start" and "end" events, differentiated by height signs. Used a multiset to keep track of current building heights, determining visible skyline points.

38. Task Scheduler: Applied a max-heap to prioritize tasks with the highest frequency. Used a cooling period (p) and a temporary list to manage tasks efficiently while respecting gaps.

<hr>

### Day 19

39. Find Median from Data Stream: Maintained two heaps: Used a max-heap for the smaller half and a min-heap for the larger half of the data. Balanced heap sizes to find the median efficiently as the top of one heap (odd size) or average of tops (even size).

40. Kth Largest Element in a Stream: Used a min-heap of size k to keep track of the k largest elements. The top of the heap represents the kth largest element after each insertion.

<hr> 

### Day 20

41. Merge Sorted Array: Merged two sorted arrays in-place by filling from the end to avoid overwriting elements. Ensured both arrays are fully traversed, handling leftover elements effectively.

42. Merge Two 2D Arrays by Summing Values: Merged two 2D arrays based on the first element, summing values when keys matched. Used a two-pointer approach for efficient traversal and merging.

<hr>
