/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1] 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

// Solution using iterative method



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
        solve(root->right, ans);
        ans.push_back(root->val);        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root, ans);
        return ans;
    }
};

// Solution using two stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        stack<TreeNode*>st1, st2;
        vector<int>ans;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode *tmp = st1.top();
            st1.pop();
            st2.push(tmp);
            if(tmp->left!=NULL)
            {
                st1.push(tmp->left);
            }
            if(tmp->right!=NULL)
            {
                st1.push(tmp->right);
            }
        }
        while(!st2.empty())
        {
            TreeNode *tmp = st2.top();
            st2.pop();
            ans.push_back(tmp->val);
        }
        return ans;
    }
};

