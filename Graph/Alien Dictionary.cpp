/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)


Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50
  */

// Solution using Topological Sort

class Solution{
    public:
    vector<int> topo(int v, vector<vector<int>>&adj)
    {
        vector<int>index(v,0), ans;
        for(int i=0; i<v; i++)
        {
            for(auto x:adj[i])
            {
                index[x]++;
            }
        }
        queue<int>q;
        for(int i=0; i<v; i++)
        {
            if(index[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node])
            {
                index[x]--;
                if(index[x]==0)
                {
                    q.push(x);
                }
            }
        }
        return ans;
    }
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<vector<int>>adj(k);
        string ans="";
        for(int i=1; i<N; i++)
        {
            string tmp1=dict[i-1];
            string tmp2=dict[i];
            int j=0;
            while(j<tmp1.length() && j<tmp2.length())
            {
                if(tmp1[j]!=tmp2[j])
                {
                    adj[tmp1[j]-'a'].push_back(tmp2[j]-'a');
                    break;
                }
                j++;
            }
        }
        vector<int>tmp=topo(k, adj);
        for(int i=0; i<k; i++)
        {
            ans+=char(tmp[i]+'a');
        }
        return ans;
    }
};
