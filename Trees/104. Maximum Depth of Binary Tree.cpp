/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
  */

// Solution using dfs

class Solution {
public:
    int dfs(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        
        int l = 1+dfs(root->left);
        int r = 1+dfs(root->right);
        return max(l,r);
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};

// Solution using queue

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*, int>>q;
        int ans=0;
        q.push({root, 1});
        while(!q.empty())
        {
            TreeNode *tmp=q.front().first;
            int t=q.front().second;
            q.pop();
            ans = max(ans, t);
            if(tmp->left)
            {
                q.push({tmp->left, t+1});
            }
            if(tmp->right)
            {
                q.push({tmp->right, t+1});
            }
        }
        return ans;
    }
};
