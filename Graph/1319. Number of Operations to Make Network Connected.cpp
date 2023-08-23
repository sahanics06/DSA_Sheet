/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where 
connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other 
computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly 
connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. 
If it is not possible, return -1.

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 
Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.
  */

// Solution using Disjoint set and finding connected components

class Disjoint{
    public:
    vector<int>parent, rank;
    Disjoint(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++)
        {
            parent[i]=i;
        }
    }
    int findParent(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=findParent(parent[x]);
    }
    void Union(int x, int y)
    {
        x=findParent(x);
        y=findParent(y);
        if(x==y)
            return;
        if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        if(rank[x]<rank[y])
        {
            parent[x]=y;
        }
        if(rank[x]==rank[y])
        {
            parent[x]=y;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int nc=0, extra=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v))
            {
                extra++; // if parent are same then already connected
            }
            else
            {
                ds.Union(u,v);// else connect the component
            }
        }
        for(int i=0; i<n; i++)
        {
            if(ds.parent[i]==i)
            {
                nc++;
            }
        }
        if(extra>=nc-1) // for n component we need n-1 edges
        {
            return nc-1;
        }
        return -1;
    }
};
