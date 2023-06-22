/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
  */

// Solution using DFS and cycle detection. If cycle is there then no possible answer

class Solution {
public:
    bool cycle(vector<vector<int>>&adj, int i, vector<int>&vis, vector<int>&path)
    {
        vis[i]=1;
        path[i]=1;
        for(auto x:adj[i])
        {
            if(!vis[x])
            {
                if(cycle(adj, x, vis, path))
                {
                    return true;
                }
            }
            else if(path[x])
            {
                return true;
            }
        }
        path[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>vis(n, 0), path(n, 0);
        vector<vector<int>>adj(n);
        for(int i=0; i<pre.size(); i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                if(cycle(adj, i, vis, path))
                {
                    return false;
                }
                path[i]=0;
            }
        }
        return true;
    }
};

// Solution using KAHN's Algorithm i.e using indegree and using this as topological sort. If ans size not equal to vertex then topological sort not possible.

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>ind(n, 0),ans;
        vector<vector<int>>adj(n);
        for(int i=0; i<pre.size(); i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        queue<int>q;
        for(int i=0; i<n; i++)
        {
            for(auto x:adj[i])
            {
                ind[x]++;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        if(q.size()==0)
            return false;
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto x:adj[tmp])
            {
                ind[x]--;
                if(ind[x]==0)
                {
                    q.push(x);
                }
            }
        }
        if(ans.size()==n)   return true;
        return false;
    }
};
