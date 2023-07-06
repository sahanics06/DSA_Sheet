/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Example 1:

Input:


Output:
2 4 5 6
Explanation:
The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no 
outgoing edges from either of them. 
Every path starting at nodes 2, 4, 5, and 6 all 
lead to either node 5 or 6.
Example 2:

Input:


Output:
3
Explanation:
Only node 3 is a terminal node, and every path 
starting at node 3 leads to node 3.
Your Task:
You don't need to read or print anything. Your task is to complete the function eventualSafeNodes() which takes an integer V denoting no. of vertices and adj denoting 
adjacency list of the graph and returns an array of safe nodes.

Expected Time Complexity: O(V + E)

Expected Space Complexity: O(V)

Constraints:

1 <= V <= 104
0 <= E <= 104
The graph won't contain self loops.
Each node in the graph has a distinct value in the range 0 to V - 1.

  */

// Solution using concept of cycle. If any node is a part of cycle or leads to a cycle cannot be in answer. DFS.

class Solution {
  public:
    bool dfs(vector<int>adj[], vector<int>&vis, vector<int>&check, vector<int>&path, int i)
    {
        vis[i]=1;
        path[i]=1;
        check[i]=0;
        for(auto x:adj[i])
        {
            if(!vis[x])
            {
                if(dfs(adj, vis, check, path, x))
                {
                    check[i]=0;
                    return true;
                }
            }
            else if(path[x])
            {
                check[i]=0;
                return true;
            }
        }
        check[i]=1;// to check all the node are covered or not in dfs call
        path[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>path(V,0), vis(V,0), check(V,0), ans;
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs(adj, vis, check, path, i);
            }
        }
        for(int i=0; i<V; i++)
        {
            if(check[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};

// Solution using concept of topological sort using indegree of vertices. BFS.

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>>ad(V);
        vector<int>ans;
        int indegree[V]={0};
        for(int i=0; i<V; i++)
        {
            for(auto x: adj[i])
            {
                ad[x].push_back(i);
                indegree[i]++;
            }
        }
        // for(int i=0; i<V; i++)
        // {
        //     for(auto x:ad[i])
        //     {
        //         indegree[x]+=1;
        //     }
        // }
        queue<int>q;
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto x:ad[tmp])
            {
                indegree[x]-=1;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
