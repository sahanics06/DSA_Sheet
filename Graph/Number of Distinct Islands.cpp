/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. 
Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).
Example 1:
Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.
Example 2:
Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.
Your Task:
You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and 
returns the total number of distinct islands.
Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)
Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
*/

//Solution

class Solution {
  public:
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, vector<pair<int,int>>&chain, int i, int j, int dx[], int dy[], int bx, int by)
    {
        int n=grid.size(), m=grid[0].size();
        vis[i][j]=0;
        chain.push_back({i-by, j-bx});
        for(int k=0; k<4; k++)
        {
            int tx=dx[k]+j;
            int ty=dy[k]+i;
            if(tx>=0&&ty>=0&&ty<n&&tx<m&&grid[ty][tx]==1&&vis[ty][tx]==-1)
            {
                dfs(grid, vis, chain, ty, tx, dx, dy, bx, by);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(), m=grid[0].size();
        set<vector<pair<int,int>>>st;    // For storing unique vectors of pair. We are subtrating every coordinates with the base value i.e with the coordinate from where 
                                         // DFS call starts for every component.
        vector<vector<int>>vis(n, vector<int>(m, -1));
        int dx[4]={0, 1, 0, -1};
        int dy[4]={1, 0, -1, 0};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]!=0&&grid[i][j]==1)
                {
                    vector<pair<int,int>>chain;
                    dfs(grid, vis, chain, i, j, dx, dy, j, i);
                    st.insert(chain);
                }
            }
        }
        return st.size();
    }
};
