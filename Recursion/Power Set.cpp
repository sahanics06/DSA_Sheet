/*
Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 subsequences that 
can be formed from abc.
Example 2:

Input: str = "aa"
Output: a a aa
Explanation : There are 3 subsequences that 
can be formed from aa.
Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes S as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from S in lexicographically-sorted order.

Expected Time Complexity: O(n*2n) where n is the length of the String
Expected Space Complexity: O(n * 2n)
 

Constraints: 
1 <= Length of String <= 16
*/

//  Solution--- Here we have to take a character and then recusively take the rest of the charaacter to form all the subsequences.
//              We have stored all the string in a vector and then sorted it lexicographically using MyCompare function.

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    static bool MyCompare(string a, string b)
	    {
	        if(a.compare(0, b.size(),b)==0 || b.compare(0, a.size(), a)==0)
	        {
	            return a.size()<b.size();
	        }
	        else
	            return a<b;
	    }
	    void subSequence(string t, string s, int i, int n, vector<string>&ans)
	    {
	        if(i==n)
	            return;
	       string tmp=t+s[i];
	       ans.push_back(tmp);
           subSequence(tmp, s, i+1, n, ans);
           subSequence(t, s, i+1, n, ans);
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n=s.length();
		    vector<string>ans;
		    for(int i=0; i<n; i++)
		    {
		        string t="";
		        t+=s[i];
		        ans.push_back(t);
		        subSequence(t, s, i+1, n, ans);
		    }
		    sort(ans.begin(), ans.end(), MyCompare);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
