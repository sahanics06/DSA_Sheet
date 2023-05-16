/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column 
number of the nearest cell having value 1. There should be atleast one 1 in the grid.

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.

Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes the grid as an input parameter and returns a matrix 
of the same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/

// Solution using BFS

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(), m=grid[0].size();
	    vector<vector<int>>ans(n, vector<int>(m, 0));
	    vector<vector<int>>vis(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>>q;
	    int dx[4]={0,1,0,-1};
	    int dy[4]={1,0,-1,0};
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i, j}, 0});
	            }
	            else
	            {
	                ans[i][j]=INT_MAX;
	            }
	        }
	    }
	    int x=q.front().first.second;
	    int y=q.front().first.first;
	    ans[y][x]=0;
	    while(!q.empty())
	    {
	        int tmp=q.front().second;
	        int x=q.front().first.second;
	        int y=q.front().first.first;
	        q.pop();
	        for(int i=0; i<4; i++)
	        {
	            int tx=x+dx[i];
	            int ty=y+dy[i];
	            if(tx>=0 &&ty>=0&&tx<m&&ty<n)
	            {
	                if(vis[ty][tx]==0)
	                {
	                    vis[ty][tx]=1;
	                    q.push({{ty, tx}, 1+tmp});
	                }
	                if(ans[ty][tx]==INT_MAX)
	                {
	                    ans[ty][tx]=min(ans[ty][tx], 1+tmp);
	                }
	            }
	        }
	    }
	    return ans;
	}
};
