/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
Example 1:
Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 
1->2->3->4->1 is a cycle.
Example 2:
Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 
No cycle in the graph.
Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and 
adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.
NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
Constraints:
1 ≤ V, E ≤ 105
*/

// BFS
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<int> adj[], vector<vector<int>>&vis, int i)
    {
        queue<int>q;
        q.push(i);
        vis[i][0]=1;
        vis[i][1]=-1;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto x:adj[t])
            {
                if(vis[x][0]==-1)
                {
                    q.push(x);
                    vis[x][0]=1;
                    vis[x][1]=t;
                }
                else if(vis[t][1]!=x)   // Important line to check the parent or else cycle.
                {
                    return true;
                }
                
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>>vis(V, vector<int>(2, -1)); // checks visited and keeps parent of node. If a node is root then its parent is -1
        for(int i=0; i<V; i++)    // For loop because there might be other components where there may be cycle present.
        {
            if(vis[i][0]==-1)
            {
               bool ans=bfs(adj, vis, i);
               if(ans==true)
            {
                return ans;
            }
            }
            
        }
        
        return false;
    }
};

// DFS------------------IMPORTANT LINE FOR RECURSION POINT OF VIEW

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int>adj[], vector<vector<int>>&vis, int node)
    {
        vis[node][0]=1;
        bool ans=false;
        for(auto x:adj[node])
        {
            if(vis[x][0]==-1)
            {
                vis[x][0]=1;
                vis[x][1]=node;
                if(dfs(adj, vis, x))
                    return true;  // IMPORTANT LINE- Here we have to return because if from lower recursion tree we are getting true then this true is to be forwaded
            }                     // to top. I was missing this line for which i was getting wrong answer.
            else if(vis[node][1]!=x)
            {
                ans=true;
                break;
            }
        }
        return ans;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<vector<int>>vis(V, vector<int>(2,-1));
        for(int i=0; i<V; i++)
        {
            if(vis[i][0]==-1)
            {
                bool ans=dfs(adj, vis, i);
                if(ans==true)
                {
                    return true;
                }
            }
            
        }
        return false;
    }
};

// DFS---------------------

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], vector<int>&vis, int node, int parent)
    {
        vis[node]=1;
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                if(dfs(adj, vis, x, node))
                {
                    return true;
                }
            }
            else if(x!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                bool ans=dfs(adj, vis, i, -1);
                if(ans)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
