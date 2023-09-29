/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
Example 2:

Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.
Your Task:

You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.

Expected Time Complexity: O(n * m)

Expected Space Complexity: O(n * m)

Constraints:

1 <= n, m <= 500
grid[i][j] == 0 or 1
*/

//Solution--- BFS Store all the edge 1s to queue and then find all 1s adjacent to 1s in queue.

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 &&(i==0 || j==0 || i==n-1 || j==m-1))
                {
                    q.push({i,j});
                }
            }
        }
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!q.empty())
        {
        pair<int,int> tmp=q.front();
        int x=tmp.second;
        int y=tmp.first;
        vis[y][x]=1;
        q.pop();
            for(int i=0; i<4; i++)
            {
                int tx=dx[i]+x;
                int ty=dy[i]+y;
                if(tx>=0&&ty>=0&&tx<m&&ty<n&&grid[ty][tx]==1&&!vis[ty][tx])
                {
                    vis[ty][tx]=1;
                    q.push({ty,tx});
                }
            }
        }
        int c=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=1)
                {
                    c++;
                }
            }
        }
        return c;
    }
};

// BFS another approach

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0, n=grid.size(), m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j] || grid[i][j]==0)
                    continue;
                int c=0;
                bool yes=true;
                queue<pair<int,int>>q({{i,j}});
                vis[i][j]=1;
                while(!q.empty())
                {
                    c++;
                    int x=q.front().second;
                    int y=q.front().first;
                    q.pop();
                    for(int k=0; k<4; k++)
                    {
                        int tx=x+dx[k];
                        int ty=y+dy[k];
                        if(tx<0||ty<0||tx>=m||ty>=n)
                        {
                            yes=false;
                            continue;
                        }
                        if(grid[ty][tx]==0)   continue;
                        if(vis[ty][tx]) continue;
                        vis[ty][tx]=1;
                        q.push({ty,tx});
                    }

                }
                if(yes)
                {
                    ans+=c;
                }
                                
            }
        }
        return ans;
    }
};

// BFS Total 1's minus 1's reachable to edge

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        queue<pair<int,int>>q;
        int total=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    if(i==0 || j==0 || i==n-1 || j==m-1)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                    total++;
                }
            }
        }
        int count=0;
        while(!q.empty())
        {
            int tx=q.front().second;
            int ty=q.front().first;
            vis[ty][tx]=1;
            count++;
            //cout<<ty<<" "<<tx<<"  "<<count<<endl;
            q.pop();
            for(int k=0; k<4; k++)
            {
                int x=tx+dx[k];
                int y=ty+dy[k];
                if(x>=0 && y>=0 && x<m && y<n && grid[y][x]==1 && vis[y][x]==0)
                {
                    q.push({y,x});
                    vis[y][x]=1; // here vis[y][x] is needed because there might be a point which is already inserted in 
                                 // queue and not yet encountered adn the same point is also added in the queue by some other 
                                 // traversal point. So their wiil be same point many time.
                }
            }
        }
        return total-count;
    }
};
