/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: [] 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
  */

// Solution 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        bool f=true;        // flag to check whether to put values inside vector in reverse way or direct way.
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int>t(n);
            for(int i=0; i<n; i++)
            {
                TreeNode* tmp=q.front();
                q.pop();
                if(f)
                {
                    t[i]=tmp->val;
                }
                else
                {
                    t[n-i-1]=tmp->val;
                }
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
            }
            f=!f;
            ans.push_back(t);
        }
        return ans;
    }
};
