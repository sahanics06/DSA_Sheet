/*
You are given an integer array nums that may contain duplicates. Your task is to return all possible subsets. Return only unique subsets and they can be in any order.

Example:

Input: 
nums = [1,2,2] 
Output: 
[[],[1],[1,2],[1,2,2],[2],[2,2]]
Explanation: 
We can have subsets ranging from length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.
Your Task:
Complete the function vector> printUniqueSubset(), which takes  a vector nums and return a vector of vector consisting of all unique subsets.

Expected Time Complexity: O(K2N).
Expected Auxiliary Space: O(K2N).

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

//  Solution

class Solution {

  public:
    void solve(int idx, int n, vector<int>&nums, vector<vector<int>>&ans, vector<int>&v)
    {
        if(idx==n)
        {
            return;
        }
        for(int i=idx; i<n; i++)
        {
            if(i>idx && nums[i]==nums[i-1])  continue;
            v.push_back(nums[i]);
            ans.push_back(v);
            solve(i+1, n, nums, ans, v);
            v.pop_back();
        }
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        ans.push_back({});
        int n=nums.size();
        solve(0, n, nums, ans, v);
        return ans;
    }
};
