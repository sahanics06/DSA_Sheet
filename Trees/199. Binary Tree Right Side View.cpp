/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered 
from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 
Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
  */

// Solution using map of column index and node value, We update every time for column value. 
// Since we traverse from left to right in level order so the end will always be the right most value of that level.

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        map<int, int>mp;
        vector<int>ans;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int y = q.front().second;
            mp[y] = node->val;
            q.pop();
            if(node->left) // We can't ignore this line because we might not have right side for a node then we have to move left side
            {
                q.push({node->left, y+1});
            }
            if(node->right)
            {
                q.push({node->right, y+1});
            }
        }
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
