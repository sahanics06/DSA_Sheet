/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

// Solution similar to Power Set done in GFG. Slight changes are made. Since here it was given as number and we have to return vector of vector.

class Solution {
public:
    void subSequence(vector<int> t, vector<int> s, int i, int n, vector<vector<int>>&ans)
	    {
	        if(i==n)
	            return;
	       	vector<int> tmp=t;
        	tmp.push_back(s[i]);
	       	ans.push_back(tmp);
          subSequence(tmp, s, i+1, n, ans);
          subSequence(t, s, i+1, n, ans);
	        
	    }
    vector<vector<int>> subsets(vector<int>& nums) {
            int n=nums.size();
		    vector<vector<int>>ans;
            ans.push_back({});
		    for(int i=0; i<n; i++)
		    {
		        vector<int>t;
		        t.push_back(nums[i]);
		        ans.push_back(t);
		        subSequence(t, nums, i+1, n, ans);
		    }
		    return ans;
    }
};
