/*
  Given the root of a binary tree, return the preorder traversal of its nodes' values.
Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]
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

// Solution iterative

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int>ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *cur=st.top();
            st.pop();
            ans.push_back(cur->val);
            if(cur->right)
            {
                st.push(cur->right);
            }
            if(cur->left)
            {
                st.push(cur->left);
            }
        }
        return ans;
    }
};

// Solution recursion

class Solution {
public:
    void solve(TreeNode *root, vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->val);
        solve(root->left, ans);
        solve(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root, ans);
        return ans;
    }
};
