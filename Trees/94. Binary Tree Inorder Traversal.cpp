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
