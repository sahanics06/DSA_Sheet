/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
Example 1:
Input: 
Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:
Input:
Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of 
the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105
*/

//Solution BFS, Bipartite means coloring alternate node with opposite color. 
//              Or can be said as coloring every node with two colors such that no two adjacent nodes have same color

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V, -1);
	    for(int i=0; i<V; i++)
	    {
	        if(vis[i]==-1)
	        {
	            queue<pair<int, int>>q;
	            q.push({i, 1});
	            vis[i]=1;
	            while(!q.empty())
	            {
	                int color=q.front().second;
	                int node=q.front().first;
	                q.pop();
	                for(auto x:adj[node])
	                {
	                    if(vis[x]==-1)
	                    {
	                        vis[x]=!color;
	                        q.push({x, !color});
	                    }
	                    else if(color==vis[x])
	                    {
                            return false;
	                    }
	                }
	            }
	        }
	    }
	    return true;
	}
};

//Solution DFS, Bipartite means coloring alternate node with opposite color. 
//              Or can be said as coloring every node with two colors such that no two adjacent nodes have same color

class Solution {
public:
    bool dfs(vector<int>adj[], vector<int>&vis, int node, int color)
    {
        vis[node]=color;
        for(auto x:adj[node])
        {
            if(vis[x]==-1)
            {
                if(dfs(adj, vis, x, !color)==false)
                    return false;
            }
            else if(vis[x]==color)
            {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V, -1);
	    for(int i=0; i<V;i++)
	    {
	        if(vis[i]==-1)
	        {
	            if(dfs(adj, vis, i, 1)==false)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};
