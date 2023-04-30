/*
Find all valid combinations of K numbers that sum upto to N such that the following conditions are true:

Only number 1 through 9 are used.
Each number is used atmost once.
Return the list of all possible valid combinations.

Note: The list must not contain the same combination twice, and the combinations returned in any order.
 

Example 1:

Input:
K = 3
N = 7
Output: { {1, 2, 4} }
Explanation: 
1+ 2+ 4 = 7
There are no other valid combinations.
 

Example 2:

Input:
K = 3
N = 9
Output: { {1, 2, 6}, {1, 3, 5}, {2, 3, 4} }
Explanation: 
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
 

Example 3:

Input:
K = 4
N = 3
Output: { { } }
Explanation: There are no valid combinations.
Using 4 different numbers in the range {1, 9}, the smallest sum we can get is 1 + 2 + 3 + 4 = 10 and since 10 > 3, there are no valid combinations.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function combinationSum() which takes the integers K and N as parameters and returns a list of all possible valid combinations.

Expected Time Complexity: O(2K)
Expected Auxiliary Space: O(K)

Constraints:
1 ≤ K ≤ 9
1 ≤ N  ≤ 60
*/

class Solution {
  public:
    void solve(int i, int k, int sum, int n, vector<int>&arr, vector<vector<int>>&ans, vector<int>&v)
    {
        if(i>=9)
        {
            if(sum==n && k==0)
            {
                ans.push_back(v);
            }
            return;
        }
        if(k==0 && sum==n)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(arr[i]);
        solve(i+1, k-1, sum+arr[i], n, arr, ans, v); // Here we are sending k-1 when taken, we cannot do k-- because on doing this vaule of k will decrease
        v.pop_back();                                // and this reduced value will be then passed in not taken call but we need to call value of k without 
        solve(i+1, k, sum, n, arr, ans, v);          // decrement since the value is not taken.
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<int>arr{1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>v;
        solve(0, K, 0, N, arr, ans, v);
        return ans;
    }
};
