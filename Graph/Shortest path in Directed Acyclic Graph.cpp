/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to 
edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Example1:

Input:
N = 4, M = 2
edge = [[0,1,2],[0,2,1]
Output:
0 2 1 -1
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->2 with edge weight 1.
There is no way we can reach 3, so it's -1 for 3.
Example2:

Input:
N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output:
0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes an integer N as number of vertices, an integer M as number of edges 
and a 2D Integer array(or vector) edges as the input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

Expected Time Complexity: O(N+M), where N is the number of nodes and M is edges
Expected Space Complexity: O(N)

Constraint:
1 <= N,M <= 100
0 <= edgei,0,edgei,1 < n
0 <= edgei,2 <=105
  */

// Solution using BFS and updating the cost till node if present ost is less than previous cost and so push that node in queue.

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        int src=0;
        vector<vector<pair<int,int>>>adj(N);
        vector<int>ans(N,INT_MAX), vis(N, -1);
        vis[src]=1;
        ans[src]=0;
        for(int i=0; i<M; i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back({y, edges[i][2]});
        }
        
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            vis[tmp]=1;
            for(auto j:adj[tmp])
            {
                int v=j.first;
                int cost=j.second;
                    if(vis[v]==-1 || ans[v]>ans[tmp]+cost)
                    {
                        vis[v]=1;
                        q.push(v);
                        ans[v]=ans[tmp]+cost;
                    }
            }
        }
        for(int i=0; i<N; i++)
        {
            if(ans[i]==INT_MAX)
            {
                ans[i]=-1;
            }
        }
        return ans;
    }
};


// Solution using Topological Sort. Since in topological sort we start with node with indegree 0 and all present nodes comes from previous nodes in sequence.
// So the order is optimised and we just need to find the lesser cost to reach a node and update it. Efficient than other algo as the sequence is already known using Topo.

class Solution {
  public:
    void topo(vector<vector<pair<int,int>>>&adj, vector<int>&vis, int source, stack<int>&st)
    {
        vis[source]=1;
        for(auto x: adj[source])
        {
            int dest=x.first;
            if(!vis[dest])
            {
                topo(adj, vis, dest, st);
            }
        }
        st.push(source);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0; i<M; i++)
        {
            int source=edges[i][0];
            int destination=edges[i][1];
            int weight=edges[i][2];
            adj[source].push_back({destination, weight});
        }
        stack<int>st;
        vector<int>vis(N,0), ans(N, INT_MAX);
        topo(adj, vis, 0, st);
        ans[0]=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            for(auto x:adj[node])
            {
                if(ans[node]+x.second<ans[x.first])
                {
                    ans[x.first]=ans[node]+x.second;
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        }
        return ans;
    }
};
