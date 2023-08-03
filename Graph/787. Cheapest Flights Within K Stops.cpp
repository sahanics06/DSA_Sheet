/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city 
fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 
Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
  */

// Solution using Dikstra Algorithm. Here we dont need priority queue, only queue works fine as we are taking number of stops as main value and stops increases by 1 so
// no need of priority queue.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<flights.size(); i++)
        {
            int s=flights[i][0];
            int d=flights[i][1];
            int p=flights[i][2];
            adj[s].push_back({d,p});
        }
        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int, int>>>pq;
        pq.push({0,{src,0}});
        dist[src]=0;
        while(!pq.empty())
        {
                int stops=pq.front().first;
                int source=pq.front().second.first;
                int p=pq.front().second.second;
                pq.pop();
                if(stops>k)
                    continue;
                for(auto x:adj[source])
                {
                    int des=x.first;
                    int price=x.second;
                    if(price+p<dist[des] && stops<=k)
                    {
                        dist[des]=price+p;
                        pq.push({stops+1,{des, price+p}});
                    }
                }
            }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
