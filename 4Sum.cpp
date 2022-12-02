/* Leetcode
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        // Your code goes here
        vector<vector<int>>v;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<n;i++)
        {
            for(int j=i+1; j<n;j++)
            {
                long long t=(long long)k-arr[i]-arr[j];
                int l=j+1,r=n-1;
                while(l<r)
                {
                    int sum=arr[l]+arr[r];
                    if(sum<t)
                    {
                        // v.push_back({arr[i],arr[j],arr[l],arr[r]});
                        // while(l<r && arr[l]==arr[l+1]) l++;
                        // while(l<r && arr[r]==arr[r-1]) r--;
                        // r--;
                        // l++;
                        l++;
                    }
                    else if(sum>t)
                    {
                        r--;
                    }
                    else
                    {
                        vector<int>v1(4,0);
                        v1[0]=arr[i];
                        v1[1]=arr[j];
                        v1[2]=arr[l];
                        v1[3]=arr[r];
                        v.push_back(v1);
                        while(l<r && v1[2]==arr[l]) ++l;
                        while(l<r && v1[3]==arr[r]) --r;
                    }
                }
                while(j+1<n && arr[j]==arr[j+1]) ++j;
            }
            while(i+1<n && arr[i]==arr[i+1]) ++i;
        }
        return v;
    }
};

// class Solution {
// public:    
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         vector<vector<int>>res;
//         if(nums.empty())
//             return res;
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<n; i++)
//         {
//             for(int j=i+1; j<n; j++)
//             {
//                 int l=j+1, r=n-1;
//                 long long t=(long long)target-nums[i]-nums[j];
//                 while(l<r)
//                 {
//                     int s=nums[l]+nums[r];
//                     if(t>s)
//                     {
//                         l++;
//                     }
//                     else if(t<s)
//                     {
//                         r--;
//                     }
//                     else
//                     {
//                         vector<int>v(4,0);
//                         v[0]=nums[i];
//                         v[1]=nums[j];
//                         v[2]=nums[l];
//                         v[3]=nums[r];
//                         res.push_back(v);
                    
                    
//                     while(l<r && v[2]==nums[l]) ++l;
//                     while(l<r && v[3]==nums[r]) --r;
//                     }  
//                 }
//                 while(j+1<n && nums[j+1]==nums[j]) ++j;
//             }
//             while(i+1<n && nums[i+1]==nums[i]) ++i;
//         }
//         return res;
//     }
// };
