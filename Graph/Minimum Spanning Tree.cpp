/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the 
edges of the Minimum Spanning Tree.

Example 1:
Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree()
which takes a number of vertices V and number of edges E and edges as input parameters and returns an integer denoting the 
sum of weights of the edges of the Minimum Spanning Tree.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 

Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.

*/

// USING PRIM'S ALGORITHM -Start with node 0 and weight as 0. Take PQ as (weight, node). 
// Add sum when node is taken from queue. Add in queue if not visited.  Minimum Spanning tree. Add in queue if not visited. Add weight to sum when taken  from queue.

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        vector<int>vis(V,0);
        while(!pq.empty())
        {
            int node= pq.top().second;
            int wt= pq.top().first;
            pq.pop();
            if(vis[node]==1)
                continue;
            sum+=wt;
            vis[node]=1;
            for(auto x:adj[node])
            {
                int des= x[0];
                int weight= x[1];
                if(vis[des]!=1)
                {
                    pq.push({weight, des});
                }
            }
        }
        return sum;
    }
};

// KRUSHKAL'S ALGO - Create adj list such that {weight,{u,v}}. Then Sort it. Then if parent of u and v are not same then add weight to MST and do Union(u,v). 
// If node is a part of component then no need to add weight.

class Solution
{
	public:
	class Disjoint_set{
	    vector<int>parent, rank;
	    public:
	    Disjoint_set(int n)
	    {
	        parent.resize(n+1);
	        rank.resize(n+1,0);
	        for(int i=0; i<n+1; i++)
	        {
	            parent[i]=i;
	        }
	    }
	    
	    int findParent(int x)
	    {
	        if(parent[x]==x)
	        {
	            return x;
	        }
	        return parent[x]=findParent(parent[x]);
	    }
	    
	    void Union(int x, int y)
	    {
	        x=findParent(parent[x]);
	        y=findParent(parent[y]);
	        if(x==y)
	        {
	            return;
	        }
	        if(rank[x]>rank[y])
	        {
	            parent[y]=x;
	        }
	        else if(rank[x]<rank[y])
	        {
	            parent[x]=y;
	        }
	        else
	        {
	            parent[x]=y;
	            rank[y]++;
	        }
	    }
	};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>>edges;
        for(int i=0; i<V; i++)
        {
            for(auto x:adj[i])
            {
                int node=x[0];
                int wt=x[1];
                edges.push_back({wt,{i,node}});
            }
        }
        int ans=0;
        Disjoint_set ds(V);
        sort(edges.begin(), edges.end());
        
        for(x:edges)
        {
            int wt=x.first;
            int u=x.second.first;
            int v=x.second.second;
            if(ds.findParent(u)!=ds.findParent(v))
            {
                ans+=wt;
                ds.Union(u,v);
            }
        }
        return ans;
    }
};
