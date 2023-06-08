/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
Example 1:
Input:
Output: 1
Explanation: 3 -> 3 is a cycle
Example 2:
Input:
Output: 0
Explanation: no cycle in the graph
Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and 
adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
Constraints:
1 ≤ V, E ≤ 105
*/

// Solution using DFS, after complete dfs mark path as unvisited so that different paths used to reach a visited node is not considered as cycle

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], vector<int>&vis, vector<int>&path, int i)
    {
        vis[i]=1;
        path[i]=1;
        for(auto x:adj[i])
        {
            if(vis[x]==-1)
            {
                if(dfs(adj, vis, path, x))
                {
                    return true;
                }
                path[x]=-1; //after complete dfs mark path as unvisited so that different paths used to reach a visited node is not considered as cycle
            }
            else if(path[x]==1)
            {
                return true;
            }
        }
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V, -1), path(V, -1);
        for(int i=0; i<V; i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(adj, vis, path, i)==true)
                {
                    return true;
                }
                path[i]=-1; //after complete dfs mark path as unvisited so that different paths used to reach a visited node is not considered as cycle
            }
        }
        return false;
// 8 8
// 6 0
// 0 2
// 2 4
// 4 7
// 7 5
// 5 1
// 1 3
// 5 6
    }
};
