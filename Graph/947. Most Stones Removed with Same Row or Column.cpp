/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest 
possible number of stones that can be removed.

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it. 

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.
  */

// Solution using Disjoint Set. 
// We make row and column as parent. For every column we give numbering as column number + Row_Size + 1. 
// We make union of row coordinate and column coordinate.
// And keep the coordinate in map for every row and column.
// For every entry of map we check if the parent is itself then it is the main parent. So increase the count_Component.
// ANswer is Total number of stones - count_Component

class Disjoint{
    public:
    vector<int>rank,parent;
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
        return parent[x] = findParent(parent[x]);
    }

    void Union(int x, int y)
    {
        x=findParent(x);
        y=findParent(y);
        if(x==y)
        {
            return ;
        }
        if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        if(rank[y]>rank[x])
        {
            parent[x]=y;
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
    int removeStones(vector<vector<int>>& stones) {
            int mxR=0, mxC=0;
            for(auto x : stones)      
            {
                mxR = max(mxR, x[0]);
                mxC = max(mxC, x[1]);
            }
            Disjoint ds(mxR+mxC+1);
            unordered_map<int,int>mp;
            for(auto x : stones)
            {
                int r = x[0];
                int c = x[1] + mxR + 1;
                ds.Union(r,c);
                mp[r]=1;
                mp[c]=1;
            }
            int count=0;
            for(auto x : mp)
            {
                if(ds.findParent(x.first)==x.first)
                {
                    count++;
                }
            }
            return stones.size()-count;
    }
};
