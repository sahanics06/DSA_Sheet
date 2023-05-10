/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500
*/

// Solution- We have initially pushed all the index having value'2' in queue and then looped it. While pushing we also pushed the height/ time since we have to
// find the minimum time to cover all the '1s'. If any '1' doesn't change to '2' then return -1;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int count=0, n=grid.size(), m=grid[0].size();
        queue<pair<pair<int,int>, int>>q;
        //vector<vector<int>>vis(n, vector<int>(m,0));
        int vis[n][m];
        int dy[]={0, 1, 0, -1};
        int dx[]={1, 0, -1, 0};
        for(int i=0;i <n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j}, 0});
                    vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int h=q.front().second;
            int y=q.front().first.first;
            int x=q.front().first.second;
            q.pop();
            count=max(count, h);
            for(int i=0; i<4; i++)
            {
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(tx>=0 && tx<m && ty>=0 && ty<n && vis[ty][tx]==0 && grid[ty][tx]==1)
                {
                    vis[ty][tx]=2;
                    q.push({{ty, tx}, h+1});
                }
            }
        }
        
        for(int i=0;i <n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        
        return count;
    }
};

// Solution - Based on BFS and a flag is marked as true and in complete covering of neighbour when we come out of inner loop then only we increment value of count by 1.
// Also if count of fresh orange and rotten orange dont match then return -1; On complete looping on size of queue we change size of queue to latest size as new values
// are pushed inside queue.

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0, n=grid.size(), m=grid[0].size();
        int fresh=0, converted=0;
        queue<pair<int,int>>q;
        int dy[]={0, 1, 0, -1};
        int dx[]={1, 0, -1, 0};
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i <n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        int s=q.size();
        bool fl=false;
        while(!q.empty())
        {
        while(s>0)
        {
            pair<int,int> val=q.front();
            q.pop();
            int y=val.first;
            int x=val.second;
            for(int i=0; i<4; i++)
            {
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(tx>=0 && tx<m && ty>=0 && ty<n && vis[ty][tx]==0 && grid[ty][tx]==1)
                {
                    vis[ty][tx]=2;
                    q.push({ty, tx});
                    fl=true;
                    converted++;
                }
            }
            s--;
        }
        if(fl)
            {
                fl=false;
                count++;
            }
        s=q.size();
        }
        if(fresh!=converted) return -1;
        
        return count;
    }
};

// Solution with slight change

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int count=-1, n=grid.size(), m=grid[0].size();
        int fresh=0, converted=0;
        queue<pair<int,int>>q;
        int d[]={0, 1, 0, -1, 0};
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i <n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        while(!q.empty())
        {
            int s=q.size();
        while(s>0)
        {
            pair<int,int> val=q.front();
            q.pop();
            int y=val.first;
            int x=val.second;
            for(int i=0; i<4; i++)
            {
                int tx=x+d[i];
                int ty=y+d[i+1];
                if(tx>=0 && tx<m && ty>=0 && ty<n && vis[ty][tx]==0 && grid[ty][tx]==1)
                {
                    vis[ty][tx]=2;
                    q.push({ty, tx});
                    converted++;
                }
            }
            s--;
        }
        count++;
        }
        if(fresh!=converted) return -1;
        if(count==-1) return 0;
        return count;
    }
};
