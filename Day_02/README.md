Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000


Approach : 

1. First I sorted the both array.
2. then took two variables as i and j , initialize it with zero.
3. Check if both i and j of arrays values are same or not
4. if i<j then i++ as i indicates the first array.
5. if J<i then j++ as j indicates the 2nd array.
