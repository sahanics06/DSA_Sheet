/*
You are given a collection of numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to the target. Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.


Example:

Input:  candidates = [10,1,2,7,6,1,5], target = 8. 
Output:  [[1,1,6], [1,2,5], [1,7], [2,6]]. 
Explanation:  These are the unique combinations whose sum is equal to the target.
Your Task:
Complete the function vector> combinationSum2(), which takes a vector "candidates" and an integer target and returns a vector of vector consisting of all unique combinations whose sum is equal to the target.


Expected Time Complexity: O(2n*k).
Expected Auxiliary Space: O(k*x).


Constraints:
1 <= candidates.length <= 100.
1 <= candidates[i] <= 50.
1 <= target <= 30.
*/

class Solution {
  public:
    void solve(int idx, int n, int target, vector<int>&candidates, vector<int>&v, vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=idx; i<n; i++)
        {
            if(i>idx && candidates[i]==candidates[i-1]) continue;  // In this line we avoid same value to avoid duplicates
            if(candidates[i]>target)
            {
                break;
            }
            v.push_back(candidates[i]);
            solve(i+1, n, target-candidates[i], candidates, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        int n=candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(0,  n, target, candidates, v, ans);
        return ans;
    }
};
