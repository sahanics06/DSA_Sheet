/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) 
and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally 
or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as 
an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500

*/

// Solution using DFS

class Solution {
  public:
    // Function to find the number of islands.
    int n,m;
    void dfs(vector<vector<char>>&grid, vector<vector<int>>&vis, int i, int j, int dx[], int dy[])
    {
        vis[i][j]=1;
        for(int k=0; k<8; k++)
        {
            int tx=dx[k]+j;
            int ty=dy[k]+i;
            if(tx>=0 && ty>=0 && tx<m && ty<n && grid[ty][tx]=='1' && vis[ty][tx]==0)
            {
                vis[ty][tx]=1;
                dfs(grid, vis, ty, tx, dx, dy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size(), m=grid[0].size();
        int count=0;
        int dx[]={0,1,1,1,0,-1,-1,-1};
        int dy[]={1,1,0,-1,-1,-1,0,1};
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    dfs(grid, vis, i, j, dx, dy);
                    count++;
                }
            }
        }
        return count;
    }
};
