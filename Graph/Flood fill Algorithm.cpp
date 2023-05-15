/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the 
starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. 
Replace the color of all of the aforementioned pixels with the newColor.

Example 1:
Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
Your Task:
You don't need to read or print anyhting. Your task is to complete the function floodFill() 
which takes image, sr, sc and newColor as input paramater and returns the image after flood filling.
Expected Time Compelxity: O(n*m)
Expected Space Complexity: O(n*m)
Constraints:
1 <= n <= m <= 100
0 <= pixel values <= 10
0 <= sr <= (n-1)
0 <= sc <= (m-1)
*/

// BFS

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size(), m=image[0].size();
        int old=image[sr][sc];
        vector<vector<int>>ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans[i][j]=image[i][j];
            }
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(!q.empty())
        {
            pair<int,int>t=q.front();
            q.pop();
            int x=t.second;
            int y=t.first;
            ans[y][x]=newColor;
            for(int i=0; i<4; i++)
            {
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(tx>=0 && ty>=0 && tx<m && ty<n && ans[ty][tx]!=newColor && ans[ty][tx]==old)
                {
                    ans[ty][tx]=newColor;
                    q.push({ty,tx});
                }
            }
        }
        return ans;
    }
};

// DFS

class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int newColor, int old, int n, int m, int dx[], int dy[])
    {
        ans[sr][sc]=newColor;
        for(int i=0; i<4; i++)
        {
            int x=sc+dx[i];
            int y=sr+dy[i];
            if(x>=0 && y>=0 && x<m && y<n && image[y][x]==old && ans[y][x]!=newColor)
                dfs(image, ans, y, x, newColor, old, n, m, dx, dy);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size(), m=image[0].size();
        int old=image[sr][sc];
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        vector<vector<int>>ans(n, vector<int>(m,-1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans[i][j]=image[i][j];
            }
        }
        dfs(image, ans, sr, sc, newColor, old, n, m, dx, dy);
        return ans;
    }
};
