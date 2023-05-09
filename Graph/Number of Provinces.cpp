/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province 
if there is a path from u to v or v to u. Your task is to find the number of provinces.
Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
Example 1:
Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1
Your Task:  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and 
an adjacency matrix adj as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.

Expected Time Complexity: O(V2)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V ≤ 500
*/

class Solution {
  public:
    void dfs(vector<vector<int>>&v, vector<int>&vis, int node)
    {
        vis[node]=1;
        for(int i=0; i<v[node].size(); i++)
        {
            if(!vis[v[node][i]])
            {
                dfs(v, vis, v[node][i]);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>v(V+1);
        vector<int>vis(V+1, 0);
        int ans=0;
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    v[i+1].push_back(j+1);  // Since we are taking nodes number from one so we are pushing i+1 and j+1.
                    v[j+1].push_back(i+1);  // Since undirected graph so from both end we have to add edges.
                }
            }
        }
        for(int i=1; i<=V; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(v, vis, i);
            }
        }
        return ans;
    }
};
