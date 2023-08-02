/*
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges describing there are edges between a to b with some weight, 
find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5

Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestPath() which takes n vertex and m edges and vector of edges having 
weight as inputs and returns the shortest path between vertex 1 to n.

Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n)

Constraint:
2 <= n <= 105
0 <= m <= 105
0<= a, b <= n
1 <= w <= 105
  */

// Solution using priority queue

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0; i<m; i++)
        {
            int s=edges[i][0];
            int d=edges[i][1];
            int w=edges[i][2];
            adj[s].push_back({d,w});
            adj[d].push_back({s,w});
        }
        vector<int>dist(n+1, INT_MAX), parent(n+1);
        parent[1]=1;
        dist[1]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,1});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            for(auto x:adj[node])
            {
                int weight_x=x.second;
                int node_x=x.first;
                if(weight+weight_x<dist[node_x])
                {
                    pq.push({weight+weight_x, node_x});
                    dist[node_x]=weight+weight_x;
                    parent[node_x]=node;
                }
            }
        }
        int i=n;
        vector<int>ans;
        while(parent[i]!=i)
        {
            ans.push_back(i);
            i=parent[i];
        }
        if(i!=1)// also if(dist[n]==INT_MAX; that means final node is not reached)
            return {-1};
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
