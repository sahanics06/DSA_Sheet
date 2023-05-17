/*
Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes n, m and mat as input parameters ad returns a 2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/

// Solution--- Using BFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O'&&(i==0 || j==0 || i==n-1 || j==m-1))
                {
                    q.push({i,j});
                }
            }
        }
        // pair<int,int> tmp=q.front();
        // int x=tmp.second;
        // int y=tmp.first;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        //vis[y][x]=1; This line give error because for multiple testcases there might be matrix having no 'O'. In that case queue in empty 
        //             so q.front()is unknown value and vis[unknown][known] is accessing out of bound value.
        //vis[3][1]=1;
        while(!q.empty())
        {
            int x=q.front().second;
            int y=q.front().first;
            vis[y][x]=1;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(tx>=0&&ty>=0&&tx<m&&ty<n&& board[ty][tx]=='O' && !vis[ty][tx])
                {
                    vis[ty][tx]=1;
                    q.push({ty, tx});
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};

// Solution using DFS

class Solution{
public:
    void dfs(vector<vector<char>>&mat, vector<vector<int>>&vis, int n, int m, int i, int j)
    {
        vis[i][j]=1;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int k=0; k<4; k++)
        {
            int tx=dx[k]+j;
            int ty=dy[k]+i;
            if(tx>=0&&ty>=0&&tx<m&&ty<n&& mat[ty][tx]=='O' && !vis[ty][tx])
            {
                vis[ty][tx]=1;
                dfs(mat, vis, n, m, ty, tx);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && mat[i][j]=='O'&&(i==0||i==n-1||j==0||j==m-1))
                {
                    dfs(mat, vis, n, m, i, j);
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==1)
                {
                    mat[i][j]='O';
                }
                else
                {
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};
