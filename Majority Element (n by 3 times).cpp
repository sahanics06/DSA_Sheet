/*
GFG
You are given a list of integers nums where each number represents a vote to a candidate. Return the ids of the candidates that have greater than n/3 votes, If there's not a majority vote, return -1. 

Example 1:
Input:
n = 11
nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output:
[5,6]
Explanation:
5 and 6 occur more n/3 times.
 

Example 2:
Input:
n=5
nums = [1,2,3,4,5]
Output:
[-1]
Your Task:
You don't need to read input or print anything. Your task is to complete the function Solve() which takes a integer n denoting a number of element and a list of numbers and return the list of number which occur more than n/3 time.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraint:
1 <=  n  <= 5 * 104
-109 <= nums[i] <= 109
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        int num1=nums[0];
        int c1=1;
        int num2,c2=1;
        int i=1;
        while(i<n)
        {
            if(num1!=nums[i])
            {
                num2=nums[i];
                break;
            }
            c1++;
            i++;
        }
       i++; // if we remove this line, it passes all test cases in GFG but fails in Leetcode for test case [4,5,3,4,4,1,0,-1,-2,4,6,7,8,4]
        while(i<n)
        {
            if(nums[i]==num1)
            {
                c1++;
            }
            else if(nums[i]==num2)
            {
                c2++;
            }
            else if(c1==0)
            {
                num1=nums[i];
                c1=1; // if we remove this line, still it passes all the test cases in GFG but fails in Leetcode [1,1,2,2,7,7,8,8,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3]
            }
            else if(c2==0)
            {
                num2=nums[i];
                c2=1; // if we remove this line, still it passes all the test cases in GFG but fails in Leetcode [1,1,2,2,7,7,8,8,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3]
            }
            else
            {
                c1--;
                c2--;
            }
            i++;
        }
        c1=0,c2=0, i=0;
        while(i<n)
        {
            if(nums[i]==num1)
            {
                c1++;
            }
            else if(nums[i]==num2)
            {
                c2++;
            }
            i++;
        }
        if(c1>n/3 && c2>n/3)
        {
            return {min(num1,num2),max(num1, num2)};
        }
        else if(c1>n/3)
        {
            return {num1};
        }
        else if(c2>n/3)
        {
            return {num2};
        }
        return {-1};    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

////////Leetcode/////////

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int num1=nums[0], c1=1;
        int num2, c2=1, i=1;
        while(i<n)
        {
            if(nums[i]!=num1)
            {
                num2=nums[i];
                break;
            }
            c1++;
            i++;
        }
        i++;
        while(i<n)
        {
            if(nums[i]==num1)
            {
                c1++;
            }
            else if(nums[i]==num2)
            {
                c2++;
            }
            else if(c1==0)
            {
                num1=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                num2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
            i++;
        }
        i=0, c1=0,c2=0;
        while(i<n)
        {
            if(nums[i]==num1)
            {
                c1++;
            }
            else if(nums[i]==num2)
            {
                c2++;
            }
            i++;
        }
        if(c1>n/3 && c2>n/3)
        {
            return {num1, num2};
        }
        else if(c1>n/3)
        {
            return {num1};
        }
        else if(c2>n/3)
        {
            return {num2};
        }
        return {};
        
    }
};

/////Leetcode/////
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0;
        int m=(int)1e9+1,n=(int)1e9+1,i=0;
        int s=nums.size();
        while(i<s)
        {
            if(nums[i]==m)
                c1++;
            else if(nums[i]==n)
                c2++;
            else if(c1==0)
            {
                m=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                n=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
            i++;
        }
        vector<int>v;
        c1=0,c2=0;
        for(int i=0; i<s; i++)
        {
            if(nums[i]==m)
                c1++;
            if(nums[i]==n)
                c2++;
        }
        if(c1>s/3)
            v.push_back(m);
        if(c2>s/3)
            v.push_back(n);
        return v;
    }
};
