/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes 
that have a distance k from the target node.

You can return the answer in any order.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: [] 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/
//*******************************************************************************************************
/* Solution
BFS to find the k distance nodes also we have to traverse along the parent direction. 
We have to keep track of visited node because when we go towards the parent then from parent node also it will traverse the left 
and right child thou the parent was invoked by child only. Also we have to find the parents for every child.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*, TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
                mp[node->left] = node;
            }
            if(node->right)
            {
                q.push(node->right);
                mp[node->right] = node;
            }
        }
        queue<pair<TreeNode*, int>>qq;
        vector<int>vis(501, 0);
        qq.push({target, 0});
        vis[target->val] = 1;
        while(!qq.empty())
        {
            int dist = qq.front().second;
            if(dist>k)
                break;
            int n=qq.size();
            while(n)
            {
                TreeNode* node = qq.front().first;
                n--;
                qq.pop();
                if(dist==k)
                {
                    ans.push_back(node->val);
                }
                if(node->left)
                {
                    if(vis[node->left->val]==0)
                    {
                        vis[node->left->val]=1;
                        qq.push({node->left, dist+1});
                    }
                }
                if(node->right)
                {
                    if(vis[node->right->val]==0)
                    {
                        qq.push({node->right, dist+1});
                        vis[node->right->val]=1;
                    }
                }
                if(mp.find(node)!=mp.end())
                {
                    TreeNode* tmp = mp[node];
                    if(vis[tmp->val]==0)
                    {
                        qq.push({tmp, dist+1});
                        vis[tmp->val]=1;
                    }
                }
            }            
        }
        return ans;
    }
};
