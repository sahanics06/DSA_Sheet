You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to 
receive the signal, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 
Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

// Solution using priority queue

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0; i<times.size(); i++)
        {
            int s=times[i][0];
            int d=times[i][1];
            int w=times[i][2];
            adj[s].push_back({d,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        q.push({0,k});
        while(!q.empty())
        {
            int t=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto x:adj[node])
            {
                int weight=x.second;
                int des=x.first;
                if(t+weight<time[des])
                {
                    time[des]=t+weight;
                    q.push({time[des], des});
                }
            }
        }
        int ans=time[1];
        for(int i=1; i<=n; i++)
        {
            if(time[i]==INT_MAX)
                return -1;
            ans=max(ans, time[i]);
        }
        return ans;
    }
};
