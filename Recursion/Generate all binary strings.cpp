/*
Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

A binary string is that string which contains only 0 and 1.

Example 1:

Input:
N = 3
Output:
000 , 001 , 010 , 100 , 101
Explanation:
None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively. 
Your Task:

You don't need to read input or print anything. Your task is to complete the function generateBinaryStrings() which takes an integer N as input and returns a list of all valid binary strings in lexicographically increasing order.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 20
*/

//  Solution---  We have to create all binary string containing 0 and 1. But condition given is that no two consecutive 1's. So we have two option
//               Either take 0 or 1. If we take 1 then next we cannot take 1. While taking either 0 or 1 we increment by one, i.e. we sent l+1 in call.
//               and if we have taken 0 taken we can call for both 1 and 0. If l==n then push back the string in answer.

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void bin(int n, int i, int l, string s, vector<string>&ans)
    {
        if(l==n)
        {
            ans.push_back(s);
            return;
        }
        if(i==1)
        {
            bin(n, 0, l+1, s+'0', ans);
        }
        else
        {
            bin(n, 0, l+1, s+'0', ans);
            bin(n, 1, l+1, s+'1', ans);
        }
        return;
    }
    void generateBinaryStrings(int num){
        //Write your code
        vector<string>ans;
        string s="";
        bin(num, 0, 1, s+'0', ans);
        bin(num, 1, 1, s+'1', ans);
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        return;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}
