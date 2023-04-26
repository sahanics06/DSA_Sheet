/*
Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.


Example 1:

Input:
N = 3
Output:
((()))
(()())
(())()
()(())
()()()
Example 2:
Input:
N = 1
Output:
()

Your Task:  
You don't need to read input or print anything. Complete the function AllParenthesis() which takes N as input parameter and returns the list of balanced parenthesis.

Expected Time Complexity: O(2N * N).
Expected Auxiliary Space: O(2*N*X), X = Number of valid Parenthesis.

Constraints:
1 ≤ N ≤ 12
*/

//  Solution--- We need to generate all the balanced parenthesi. Here we hav e two option either take '(' or take ')'. 
//              But we cannot take ')' unless we have '('  in greater number. So we take '(' only when count of '(' is greater than count of ')'.
//              We have taken two variable 'c' and 'd' for count of open parenthesis and close parenthesis.
#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void parent(int n, int c, int d, string s, vector<string>&ans)
    {
        if(c==d&&c==n)
        {
            ans.push_back(s);
        }
        if(c<n)
            parent(n, c+1, d, s+'(', ans);
        if(d<c)
            parent(n, c, d+1, s+')', ans);
        return;
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        parent(n, 1, 0, "(", ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
