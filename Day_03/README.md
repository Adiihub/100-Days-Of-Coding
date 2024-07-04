Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

**Approach to Solve this : **

Find the First Occurrence:
Use binary search to find the first position where the target appears in the array. This will be the starting index of the target.
If the middle element of the current search range is greater than or equal to the target, narrow the search to the left half. Otherwise, narrow the search to the right half.

Find the Last Occurrence:
Use binary search to find the last position where the target appears in the array. This will be the ending index of the target.
If the middle element of the current search range is greater than the target, narrow the search to the left half. Otherwise, narrow the search to the right half.


Verify if the indices found in steps 1 and 2 are valid by checking if they fall within the array bounds and the elements at these positions match the target.
If valid, return the indices of the first and last occurrences. Otherwise, return [-1, -1].
