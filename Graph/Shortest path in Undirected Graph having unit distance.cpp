/*
You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for 
that vertex.

Example:

Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes a 2d vector or array edges representing the edges of undirected graph 
with unit weight, an integer N as number nodes, an integer M as number of edges and an integer src as the input parameters and returns an integer array or vector, 
denoting the vector of distance from src to all nodes.

Constraint:
1<=n,m<=100
1<=adj[i][j]<=100

Expected Time Complexity: O(N + E), where N is the number of nodes and E is edges
Expected Space Complexity: O(N)
  */

// Solution using BFS

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>>adj(N);
        vector<int>ans(N,-1), vis(N, -1);
        vis[src]=1;
        ans[src]=0;
        for(int i=0; i<M; i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        queue<pair<int,int>>q;
        q.push({src, 0});
        while(!q.empty())
        {
            int tmp=q.front().first;
            int len=q.front().second;
            q.pop();
            vis[tmp]=1;
            for(auto j:adj[tmp])
            {
                    if(vis[j]==-1)
                    {
                        vis[j]=1;
                        q.push({j, len+1});
                        ans[j]=len+1;
                    }
            }
        }
        return ans;
    }
};
