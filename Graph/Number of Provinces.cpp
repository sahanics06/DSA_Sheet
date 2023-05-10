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

// Solution using DFS
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

// Solution using BFS

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size(), c=0;
        vector<vector<int>>adj(v);
        vector<int>vis(v,0);
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<isConnected[i].size(); j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }                
            }
        }
        queue<int>q;
        for(int i=0; i<v; i++)
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;
                c++;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(int i=0; i<adj[node].size(); i++)
                    {
                        if(!vis[adj[node][i]])
                        {
                            vis[adj[node][i]]=1;
                            q.push(adj[node][i]);
                        }
                    }
                }
            }
            
        }
        return c;
        
    }
};

// Solution using DSU

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x, int y)
    {
        x=find(parent[x]);
        y=find(parent[y]);
        if(x==y)
            return;
        if(rank[x]<rank[y])
        {
            parent[x]=y;
        }
        else if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        else
        {
            parent[x]=y;
            rank[y]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size(), count=0;
        vector<vector<int>>adj(v);
        parent.resize(v);
        rank.resize(v);
        for(int i=0; i<v; i++)
        {
            parent[i]=i;
        }
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<isConnected[i].size(); j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                int node=adj[i][j];
                if(find(i)!=find(node))
                {
                    count++; // We are connecting the edges to form the graph. Count is the number of reduced components on every union.
                    Union(i, node);

                }
            }
        }
        return v-count;

    }
};
