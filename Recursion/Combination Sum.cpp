/*
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.


Example 1:

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)
Example 2:

Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)

Your Task:
Your task is to complete the function combinationSum() which takes the array A and a sum B as inputs and returns a list of list denoting the required combinations in the order specified in the problem description. The printing is done by the driver's code. If no set can be formed with the given set, then  "Empty" (without quotes) is printed.


Expected Time Complexity: O(X2 * 2N), where X is average of summation B/arri for every number in the array.
Expected Auxiliary Space: O(X * 2N)

*/
// Solution brute froce. Time limit exceeded. Recursion call for all possibility.

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int i, int tmp, int n, int sum, vector<int>v, vector<int>a, vector<vector<int>>&ans)
    {
        if(i==n)
            return;
        int t=tmp;
        tmp+=a[i];
        if(tmp>sum)
            return;
        v.push_back(a[i]);
        
        if(tmp==sum)
        {
            ans.push_back(v);
            return;
        }
        solve(i, tmp, n, sum, v, a, ans);
        solve(i+1, tmp, n, sum, v, a, ans);
        v.pop_back();
        solve(i+1, t, n, sum, v, a, ans);
        return;
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(), A.end());
        vector<vector<int>>ans;
        vector<int>v;
        set<vector<int>>s;
        solve(0, 0, A.size(), B, v, A, ans);
        for(int i=0; i<ans.size(); i++)
        {
            s.insert(ans[i]);
        }
        vector<vector<int>>result;
        for(auto x:s)
        {
            result.push_back(x);
        }
        return result;
    }
};
