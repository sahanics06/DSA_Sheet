/*
Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

 

Expected Time Complexity: O(n! * n)

Expected Space Complexity: O(n)

 

Constraints:
1 <= length of string <= 5
*/

class Solution
{
	public:
	    void solve(string s, vector<string>&ans, string tmp, vector<int>f)
	    {
	        if(tmp.length()==s.length())
	        {
                ans.push_back(tmp);
	            return;
	        }
	        for(int i=0; i<s.length(); i++)
	        {
	            if(i!=0 && s[i]==s[i-1] && !f[i-1]) continue; // This line checks for the Duplicate values
	            if(!f[i])
	            {
	                f[i]=1;
	                tmp+=s[i];
	                solve(s, ans, tmp, f);
	                tmp.pop_back();
	                f[i]=0;
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    vector<int>f(S.length(), 0);
		    string tmp=S;
		    string v="";
		    sort(tmp.begin(), tmp.end());
		    solve(tmp, ans, v, f);
		    return ans;
		}
};
