/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency 
list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them.
If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2
*/

// Solution using BFS

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ind(V, 0), ans;
	    for(int i=0; i<V; i++)
	    {
	        for(auto x:adj[i])
	        {
	            ind[x]++; // Calculate indegree for every node
	        }
	    }
	    queue<int>q;
	    for(int i=0; i<V; i++)
	    {
	        if(ind[i]==0)
	        {
	            q.push(i);  // Starting with Vertexes having indegree 0
	        }
	    }
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto x:adj[node])
	        {
	            ind[x]--;
	            if(ind[x]==0) // If indegree becomes 0 then it can come in topological sort answer
	            {
	                q.push(x);
	            }
	        }
	    }
	    return ans;
	}
};

// Solution using DFS

class Solution
{
	public:
	void dfs(vector<int> adj[], int i, vector<int>&ans, vector<int>&vis)
	{
	    vis[i]=1;
	    for(auto x:adj[i])
	    {
	        if(!vis[x])
	        {
	            dfs(adj, x, ans, vis);
	        }
	    }
	    ans.push_back(i);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V, 0), ans;
	    for(int i=0; i<V; i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj, i, ans, vis);
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};
