/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). 
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, 
and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
 
Example 1:

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:

Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:

Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort. 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
  */

// Solution using Dikstra Algorithm and priority queue.

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>  >pq;
        pq.push({0,{0,0}});
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        dist[0][0]=0; 
        while(!pq.empty())
        {
            int diff=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1)
            {
                ans=diff;
                return ans;
            }
            for(int k=0; k<4; k++)
            {
                int t_i=dx[k]+i;
                int t_j=dy[k]+j;
                if(t_i>=0 && t_j>=0 && t_i<n && t_j<m)
                {
                    int abs_diff=max(abs(heights[t_i][t_j]-heights[i][j]), diff);
                    // if(t_i==n-1&&t_j==m-1)
                    // {
                    //     ans=min(ans, abs_diff);
                    // }
                    if(abs_diff<dist[t_i][t_j])
                    {
                        dist[t_i][t_j]=abs_diff;
                        pq.push({abs_diff,{t_i, t_j}});
                    }
                }
                
            }
        }
        return ans;
    }
};
