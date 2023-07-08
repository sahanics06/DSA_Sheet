/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
 

Constraints:

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104
  */

// Solution using solution. We use sorting because we need to maximise the sum of all pair where from pair we have to take the minimum one. So if we sort the array then we
// can pair the minimum together so that when we pair the maximum two numbers together we get the maximum of that which will add more in the answer.

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum=0, n=nums.size();
        for(int i=0; i<n; i+=2)
        {
            sum+=min(nums[i], nums[i+1]);
        }
        return sum;
    }
};

// Solution using counting sort. Taken from Leetcode editorial

class Solution {
public:
    const static int K = 10000;
        
    int arrayPairSum(vector<int>& nums) {
        // Store the frequency of each element
        int elementToCount[2 * K + 1] = {0};
        for (int element : nums) {
            // Add K to element to offset negative values
            elementToCount[element + K]++;
        }
        
        // Initialize sum to zero
        int maxSum = 0;
        bool isEvenIndex = true;
        for (int element = 0; element <= 2 * K; element++) {
            while (elementToCount[element]) {
                // Add element if it is at even position
                maxSum += (isEvenIndex ? element - K : 0);
                // Flip the value (one to zero or zero to one)
                isEvenIndex = !isEvenIndex;
                // Decrement the frequency count
                elementToCount[element]--;
            }
        }
        return maxSum;
    }
};

