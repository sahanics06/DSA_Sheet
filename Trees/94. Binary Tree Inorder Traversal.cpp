/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1] 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
  */

// Solution using iterative method

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* node=root;
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty()==true)  break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};


// Solution using recursion

class Solution {
public:
    void solve(TreeNode *root, vector<int>&ans)
    {
        if(root==NULL)
        {
            return ;
        }
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};

// Solution using Moris inorder traversal

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

 // 1st case: if left is null, print current node and go right
 // 2nd case: before going left, make right most node on left subtree connected to current node, then go left
 // 3rd case: if thread is already pointed to current node, then remove the thread
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode* prev = cur->left;
                while(prev->right && prev->right!=cur)
                {
                    prev = prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right = cur; // the right most node of left subtree is NULL so point it to cur
                    cur = cur->left;
                }
                else
                {
                    // This is the 3rd case, here prev->right is connected to cur so we need to insert in ans
                    // and cur is taken to prev->right i.e the node parent to left subtree. So
                    // since cur reached to subtree parent so now go towards right i.e. cur=cur->right
                    prev->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};
