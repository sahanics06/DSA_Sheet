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

// Minimum Spanning tree. Add in queue if not visited. Add weight to sum when taken  from queue.

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
