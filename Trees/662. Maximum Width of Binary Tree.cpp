/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null 
nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the 
length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer. 

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2). 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
  */

// Solution find the left most node index and right most index in every level and then find by last-first+1.

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        long long ans=0;
        while(!q.empty())
        {
            int n=q.size();
            long long first, last;
            long long idx=q.front().second; // to make index starting from 0 for everynode other there will be overflow
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front().first;
                long long cur_idx = q.front().second-idx;
                q.pop();
                if(i==0)
                {
                    first = cur_idx;
                }
                if(i==n-1)
                {
                    last = cur_idx;
                }
                if(node->left)
                {
                    q.push({node->left, 2*cur_idx+1});
                }
                if(node->right)
                {
                    q.push({node->right, 2*cur_idx+2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
