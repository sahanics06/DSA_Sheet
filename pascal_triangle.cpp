/*
GFG pratcise

Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

Example :
1
1 1
1 2 1
1 3 3 1
For N = 3, return 3rd row i.e 1 2 1

Example 1:

Input:
N = 4
Output: 1 3 3 1
Explanation: 4th row of pascal's triangle
is 1 3 3 1.
Example 2:

Input:
N = 5
Output: 1 4 6 4 1
Explanation: 5th row of pascal's triangle
is 1 4 6 4 1.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ N ≤ 1000
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll>v(n);
        if(n==1)
        {
            return {1};
        }
        if(n==2)
        {
            return {1,1};
        }
        v.push_back(1);
       // v.push_back(1);
        ll mod=pow(10,9)+7;
        for(ll i=0; i<n; i++)
        {
            vector<ll>a(i+1);
            a[0]=a[i]=1;
            for(int j=1;j<i; j++)
            {
                a[j]=(v[j]+v[j-1])%mod;
            }
            for(ll k=0; k<a.size(); k++)
            {
                v.resize(i+1);
                v[k]=a[k];
            }
        }
        return v;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends

/* Leetcode */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v(numRows);
        for(int i=0; i<numRows; i++)
        {
            v[i].resize(i+1);
            v[i][0]=v[i][i]=1;
            for(int j=1; j<i; j++)
            {
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        return v;
    }
};
