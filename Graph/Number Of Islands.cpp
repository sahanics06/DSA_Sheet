/*
You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations.
Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no 
land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change 
the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.

Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011

Example 2:

Input: n = 4
m = 5
k = 4
A = {{0,0},{1,1},{2,2},{3,3}}

Output: 1 2 3 4
Explanation:
0.  00000
    00000
    00000
    00000
1.  10000
    00000
    00000
    00000
2.  10000
    01000
    00000
    00000
3.  10000
    01000
    00100
    00000
4.  10000
    01000
    00100
    00010
 
Your Task:
You don't need to read or print anything. Your task is to complete the function numOfIslands() which takes an integer n 
denoting no. of rows in the matrix, an integer m denoting the number of columns in the matrix and a 2D array of size k 
denoting  the number of operators.

Expected Time Complexity: O(m * n)
Expected Auxiliary Space: O(m * n)

Constraints:

1 <= n,m <= 100
1 <= k <= 1000

*/

// Solution using Disjoint Set

class Disjoint{
    public:
    vector<int>rank, parent;
    Disjoint(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++)
        {
            parent[i]=i;
        }
    }
    int findParent(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=findParent(parent[x]);
    }

    void Union(int x, int y)
    {
        x=findParent(x);
        y=findParent(y);
        if(x==y)
            return ;
        if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        if(rank[y]>rank[x])
        {
            parent[y]=x;
        }
        if(rank[x]==rank[y])
        {
            parent[x]=y;
            rank[y]++;
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &queries) {
 
    int total=n*m;
    vector<int>ans;
    Disjoint ds(total);
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    vector<vector<int>>grid(n, vector<int>(m,0));
    int count=0;
    for(auto it:queries)
    {
        int x=it[1];
        int y=it[0];
        if(grid[y][x]==1)
        {
            ans.push_back(count); // There are same queries
            continue;            
        }

        grid[y][x]=1;
        count++;
        for(int k=0; k<4; k++)
        {
            int tx=x+dx[k];
            int ty=y+dy[k];
            if(tx>=0 && ty>=0 && tx<m && ty<n && grid[ty][tx]==1)
            {
                int u=ty*m+tx;
                int v=y*m+x;

                int p_u=ds.findParent(u);
                int p_v=ds.findParent(v);
                if(p_u!=p_v)
                {
                    count--;
                }
                ds.Union(u,v); 
            }
        }
        ans.push_back(count);
    }
    return ans;
    }
};
