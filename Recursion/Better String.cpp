/*
Given a pair of strings, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.

If both the strings have equal count of distinct subsequence then return str1.

Example 1:

Input:
str1 = "gfg", str2 = "ggg"
Output: "gfg"
Explanation: "gfg" have 7 distinct subsequences whereas "ggg" have 4 distinct subsequences. 
Example 2:

Input: str1 = "a", str2 = "b"
Output: "a"
Explanation: Both the strings have only 1 distinct subsequence. 
Constraints:
1 <= str1.lenght , str2.length <= 30

Your Task:
You don't need to read input or print anything. Your task is to complete the function betterString() which takes str1 and str2 as input parameters and returns the better string.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/

// This solution recursively call for every character. Time complexity- 2^n
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void unique(string s, string t, int i, unordered_set<string>&st)    // In this solution we have used brute force method to find all the subsequence 
    {                                                                   // and keeping all the string in an unordered set to avoid duplicate string.
        if(i==s.length())
            return;
        string tmp=t+s[i];
        st.insert(tmp);
        unique(s, tmp, i+1, st);
        unique(s, t, i+1, st);
    }
    string betterString(string str1, string str2) {
        unordered_set<string>st1,st2;
        string t="";
        unique(str1, t, 0, st1);
        unique(str2, t, 0, st2);
//         for(int i=0; i<str1.length(); i++)   // We dont need to loop for every character since this choosing one character and recursively call for other
//         {                                    // character is already done by recursion function.
//             unique(str1, t, i, st1);
//         }
//         t="";
//         for(int i=0; i<str2.length(); i++)
//         {
//             unique(str2, t, i, st2);
//         }
        // cout<<st1.size()<<endl;
        // cout<<st2.size()<<endl;
        return st1.size()>=st2.size()?str1:str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// Efficient way using dynamic programming. Time complexity O(N) and space O(N).

class Solution {
  public:
    void solve(string s, vector<int>&dp, int n)
    {
        dp[0]=1;
        vector<char>last(256,-1);
        for(int i=1; i<=n; i++)
        {
            dp[i]=2*dp[i-1];
            if(last[s[i-1]]!=-1)
            {
                dp[i]=dp[i]-dp[last[s[i-1]]];
                last[s[i-1]]=i-1;
            }
            last[s[i-1]]=i-1;
        }
    }
    string betterString(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<int>dp1(n+1, -1);
        vector<int>dp2(m+1, -1);
        solve(str1, dp1, n);
        solve(str2, dp2, m);
        return dp1[n]>=dp2[m]?str1:str2;
    }
};

// Efficient way Time complexity O(N), Space complexity O(unique character) i.e. constant space

class Solution {
  public:
    int solve(string s, unordered_map<char, int>mp, int n)
    {
        int lc=0, ac=0;             // lc- level count- it gives us the possible subsequences for the character at that level
        for(int i=0; i<n; i++)      // ac- all count- it gives the total subsequences at evey level.
        {                           // example string s="abca". lc=0, ac=0;
            lc=ac+1;                // 1st iteration- lc=ac+1=0+1=1 . {a}
            if(mp[s[i]]==-1)                       ac=ac+lc=0+1=1 . {a}     mp[a]=lc=1
            {                       // 2nd iteration- lc=ac+1=1+1=2  with 'b'->  {ab,b}
                ac+=lc;                            ac=ac+lc=1+2=3  Total-> {a, ab, b}   mp[b]=lc=2
            }                       // 3rd iteration- lc=ac+1=3+1=4  with 'c'->  {ac, abc, bc, c}
            else                                   ac=ac+lc=4+3=7   Total-> {a, ab, b, ac, abc, bc, c}   mp[c]=lc=4
            {                       // 4th iteration- here we see 'a' is repeating, therefore we have to remove subsequences occured previously by 'a' because we are calculating
            }                       //               it in this loop also. Example {a} is repeated.
                ac=ac+lc-mp[s[i]];  //               lc=ac+1=7+1=8  with 'a'->  {aa, aba, ba, aca, abca, bca, ca, a}
            mp[s[i]]=lc;            //               ac=ac+lc-m[a]=7+8-1=14    Total-> {a, ab, b, ac, abc, bc, c,aa, aba, ba, aca, abca, bca, ca}
        }                           // return ac   14 answer
        return ac;
        
    }
    string betterString(string str1, string str2) {
        unordered_map<char, int>mp,mm;
        int n=str1.length(), m=str2.length();
        for(int i=0; i<n; i++)
        {
            mp[str1[i]]=-1;
        }
        for(int i=0; i<m; i++)
        {
            mm[str2[i]]=-1;
        }
        int ans1=solve(str1, mp, n);
        int ans2=solve(str2, mm, m);
        return ans1>=ans2?str1:str2;
    }
};
