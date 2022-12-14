/* Leetcode
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>>v;
        for(int i=0; i<n-2; i++)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                
            int j=i+1,k=n-1;  // here we can find sum=0-nums[i] and then find if(sum==nums[l]+nums[r] inside the while loop
            while(j<k)
            {
                int sum=nums[j]+nums[k]+nums[i];
                if(sum==0)
                {
                    v.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])
                        j++;
                    while(k>j && nums[k]==nums[k-1])
                        k--;
                    j++;k--;
                }
                else if(sum>0)
                    k--;
                else
                    j++;
            }
            }
        }
        return v;
    }
};

/*____________________________________same approach-----------------*/
 
 class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        int l, r;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0; i<n-2; i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
               {
                l=i+1; r=n-1; // here we can find sum=0-nums[i] and then find if(sum==nums[l]+nums[r] inside the while loop below
                while(l<r)
                {
                    int sum=nums[i]+nums[l]+nums[r];
                    if(sum==0)
                    {
                        v.push_back({nums[i],nums[l],nums[r]});
                        while(l<r && nums[r-1]==nums[r])
                        {
                            r--;
                        }
                        while(l<r && nums[l]==nums[l+1])
                        {
                            l++;
                        }
                        l++;
                        r--;

                    }
                    else if(sum>0)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
               }
        }
        return v;
    }
};
