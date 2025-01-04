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

### Day 21

43. Sort Array By Parity: Iterated through the array and moved even numbers to the front using a two-pointer technique. Simple and efficient with in-place swapping for even and odd numbers.

44. Sort Array By Parity II: Placed even numbers at even indices and odd numbers at odd indices using two pointers. Swapped numbers using a XOR-based trick for in-place operations.

45. Rearrange Array Elements by Sign: Arranged positive and negative numbers alternately by filling positions based on their indices. Maintained order of appearance for both positive and negative numbers.

<hr>

### Day 22

46. Find First and Last Position of Element in Sorted Array: Used two custom binary search functions to locate the first and last positions of the target. The approach ensures logarithmic time complexity for efficient searching.

47. Special Array With X Elements Greater Than or Equal X: Sorted the array and used lower_bound to count elements greater than or equal to a candidate value 
𝑥 x.

48. Find Smallest Letter Greater Than Target: Implemented binary search to find the smallest letter larger than the target, wrapping around if necessary. Carefully managed indices to handle edge cases like the circular nature of the input.

<hr>

### Day 23

49.  Remove Duplicates from Sorted Array: Maintained a slow pointer i for unique elements while iterating with a fast pointer j. Replaced duplicate elements in-place to reduce array size.

50.  Remove Element: Used a loop and iterator to identify and erase occurrences of a specific value in the array. Managed iterator adjustments carefully to avoid skipping elements.

51. Partition Array According to Given Pivot: Divided elements into three groups: less than, equal to, and greater than the pivot. Combined groups sequentially to create the final partitioned array.

<hr>

### Day 24

52. Reduce Array Size to The Half: Count frequencies of elements using a hash map. Use a descending multiset to sort frequencies by magnitude. Remove elements until the array size is halved.

53. Relative Sort Array: Maintain frequency counts of arr1 in a map. Fill arr1 using arr2’s order for matching elements. Append the remaining elements in ascending order.

54. Maximum Ice Cream Bars: Sort ice cream costs in ascending order. Iteratively purchase ice creams until the coin budget is exhausted.

<hr>

### Day 25

55. Valid Parentheses: Used a stack to match opening and closing brackets ((), {}, []). At the end, if the stack is empty, the string is valid.

56. Maximum Nesting Depth of the Parentheses: Counted the deepest level of nested parentheses by tracking the number of active. Updated the maximum depth whenever a new ( is encountered.

57. Minimum Add to Make Parentheses Valid: Maintained a count of unmatched opening and closing parentheses. Increment opening for ( and decrement it if a valid ) matches an unmatched.

<hr>

### Day 26

58. Maximum Frequency Stack: Implemented a stack-like data structure that pops the most frequent element. Used a max-heap (priority_queue) to manage elements with frequency and position.

59. Min Stack: Is a stack that supports retrieving the minimum element in constant time. Here, I've used an auxiliary array to track the minimum values at each level.

<hr>

### Day 27

60. Design a Stack With Increment Operation: A stack implemented with an additional increment operation. Tracked incremental additions to stack elements efficiently using an auxiliary array.

<hr>

### Day 28

61. Simplify Path: Used a stack to handle hierarchical navigation (.. and .) efficiently. String processing with delimiters is key for path simplification.

62. Merge Intervals: Sorted intervals by start time simplifies merging overlaps. Used condition-based updates to merge or add new intervals.

<hr>

### Day 29

63. Asteroid Collision: Used a stack to simulate real-time decision-making for colliding asteroids. Handled cases of destruction, survival, or mutual annihilation with conditions.

64. Evaluate Reverse Polish Notation: Stacked simplified evaluating postfix expressions by processing operators after operands. Efficiently handled the operations and also used a helper function and integer parsing. 

<hr>

### Day 30

65. Next Greater Element I: Used a stack to efficiently find the next greater element for every item in an array. Then I've stored the results in a map for quick access and handled missing elements gracefully.

66. Final Prices With a Special Discount in a Shop: Here I've used a stack to find the nearest smaller price for discounts. Maintained indices in the stack for easy updates to the result array.

<hr>

### Day 31

67. Shortest Unsorted Continuous Subarray: Identified the smallest segment of the array that, when sorted, makes the entire array sorted. Then used pointers to expand the unsorted range by checking boundary conditions.

68. The Number of Weak Characters in the Game: Sorted characters by attack in ascending order, and by defense in descending order for ties. Traversed from the back to track the maximum defense and count weaker characters.

69. Remove Duplicate Letters: Used a stack to maintain the lexicographically smallest result while ensuring no duplicate letters. Tracked the last occurrence of characters and ensure their order is preserved when popping the stack.

<hr>

### Day 32

70. Maximum Score of a Good Subarray: Expanded the subarray by moving left or right based on which boundary has a higher value. Tracked the minimum value in the subarray to calculate the score efficiently.

71. Minimum Number of Increments on Subarrays to Form a Target Array: Calculated the difference between consecutive elements to determine required increments. Added the differences where the current value is greater than the previous one.

<hr>

### Day 33

72. Count Submatrices With All Ones: Build a histogram of consecutive 1s for each column to simplify counting. Here I've used nested loops to calculate the total number of submatrices by tracking the minimum height across columns.

73. Smallest Subsequence of Distinct Characters: Used a stack to build the result string while maintaining lexicographical order. Tracked the last occurrence of characters and avoid duplicates with a seen array.

<hr>

### Day 34

74. First non-repeating in a stream: Here I've used a queue to track characters as they appear, and a map to store their frequencies. Efficiently find the first non-repeating character by popping elements with frequency >1.

75. Reverse First K elements of Queue: Then here tried using a stack to reverse the first k elements of a queue. Append the remaining elements back to the queue to maintain the order.

<hr>

### Day 35

76. Aggressive Cows: The solution uses binary search to find the largest minimum distance for placing cows in stalls. A helper function checks feasibility by placing cows greedily while maintaining the minimum distance constraint.

<hr>

### Day 36

77. Permutations: Used backtracking to generate all possible arrangements of a given set of numbers. Maintained a temporary array for the current permutation and a set to avoid duplicate usage of elements.

<hr>

### Day 37

78.  Combination Sum II: Here I've used backtracking to find combinations that sum up to a target, avoiding duplicate results by skipping consecutive identical elements in the sorted input array. Each candidate can be used only once in a combination, and the recursion ensures all possibilities are explored without redundancy.

<hr>

### Day 38

79. Subsets: Used backtracking to generate all possible subsets of a given array by deciding for each element whether to include it or not. Maintained a temporary list to store the current subset and explore all combinations recursively.

<hr>

### Day 39

80. N-Queens: Used backtracking to place queens row by row, ensuring they don't attack each other. Then checked if a queen placement is valid by looking at the column, left diagonal, and right diagonal above the current row. After which I tried restoring the board state after exploring a solution to try other possibilities.

<hr>

### Day 40

81. All Nodes Distance K in Binary Tree: Here I've used a preorder traversal to map each node to its parent for easy traversal in all directions (left, right, and parent).
Also used a BFS (Breadth-First Search) approach starting from the target node to find all nodes at a distance k, ensuring nodes are not revisited using a visited set.

<hr>

### Day 41

82. Binary Tree Right Side View: This solution uses a modified pre-order traversal (right-first) to efficiently capture the first node visible at each level. The approach simulates the perspective of viewing the tree from the right side, ensuring an accurate representation. 

<hr>

### Day 42

83. Construct Binary Tree from Preorder and Inorder Traversal: Here I've used the preorder traversal that identifies the root nodes in sequence, while the inorder traversal divides the tree into left and right subtrees. Using recursion, the tree is constructed by systematically partitioning the inorder array and aligning it with the preorder traversal to progress through the nodes.

<hr>

### Day 43

84. Minimum Distance Between BST Nodes: Here tried performing an **inorder traversal** on a Binary Search Tree (BST) ensures node values are retrieved in ascending order, which simplifies finding the **minimum difference** between any two nodes by comparing consecutive elements in this sequence. This approach efficiently utilizes the BST properties to achieve the result.

<hr>

### Day 44

85. Lowest Common Ancestor of a Binary Tree: Here a binary tree is found by recursively traversing the tree. If the current node matches one of the target nodes, it may be the LCA. The algorithm checks both left and right subtrees: if both return valid nodes, the current node is the LCA; otherwise, the non-null result is carried upwards. This approach is simple, recursive, and effectively determines the LCA.

<hr>

### Day 45

86. Lowest Common Ancestor of a Binary Search Tree: Used the BST property to find the LCA. If the root's value lies between the two nodes, it is the LCA. Otherwise, recursively explore the left or right subtree depending on where the target nodes lie relative to the root. This approach leverages BST properties for efficiency.

87. Recover Binary Search Tree: To fix a BST where two nodes are swapped, here performed an in-order traversal to identify misplaced nodes. The first node is detected when a value is larger than the subsequent one, and the second node is marked later. Finally, swap their values to restore the BST. This process ensures minimal traversal while maintaining correctness.

<hr>

### Day 46

88. Vertical Order Traversal of a Binary Tree: Used a map to organize nodes based on their column and row positions during a breadth-first search (BFS). For nodes in the same row and column, use a multiset to maintain sorted order. This structured approach ensures accurate vertical grouping while maintaining the required order for nodes at the same level.

<hr>

### Day 47

89. Binary Tree Maximum Path Sum: Here I've tried calculating the sum of paths including the current node, left and right subtrees, and individual branches. Then used recursion to explore all paths and maintain a global maximum while returning the best branch contribution for upward paths.

<hr>

### Day 48

90. Partition Equal Subset Sum: The solution checks if an array can be divided into two subsets with equal sums by leveraging dynamic programming. It determines whether a subset with a target sum (half of the total sum) can be formed. The DP array is updated in reverse to ensure each number is considered only once for forming subsets.

<hr>

### Day 49

91: Minimum Path Sum: This code focuses on finding the path from the top-left to the bottom-right of a grid with the smallest sum of values along the way. Used recursion with memoization (DP), we efficiently calculate the minimum path by exploring both possible moves—down and right—and storing results to avoid redundant calculations.

<hr>


