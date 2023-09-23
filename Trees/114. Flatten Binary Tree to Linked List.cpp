/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left 
child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 
Follow up: Can you flatten the tree in-place (with O(1) extra space)?
*/

//***********************************************************************************************************

// Solution, here for every left subtree we connect the right most node of left subtree to first node of right subtree recursively
// and point the parent node's right to it left. This way a path is created covering left to right.

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
    void solve(TreeNode* root, TreeNode** prev)
    {
        if(root==NULL)
            return ;
        solve(root->right, prev);
        solve(root->left, prev);
        root->right = *prev;
        *prev = root;
        root->left = NULL;
    }
    void flatten(TreeNode* root) {
        TreeNode *pre=NULL;
        solve(root, &pre);        
    }
};

//***************************************************************************************************************

// Solution using Stack, For every node we push right and then left in stack. For every node we do node->right to stack top.
// and node->left to NULL

lass Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)   return ;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if(cur->right)
            {
                st.push(cur->right);
            }
            if(cur->left)
            {
                st.push(cur->left);
            }
            if(!st.empty())
            {
                cur->right=st.top();
            }
            cur->left=NULL;
        }
    }
};

//***************************************************************************************************************

// Solution using Moris traversal
// If we have left node then we go to right most node of left subtree and connect it to subtree parent's right and then 
// make parent's node->right to parent's node->left and also make parent's node->left=NULL

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->left)
            {
                TreeNode *prev = cur->left;
                while(prev->right)
                {
                    prev=prev->right;
                }
                prev->right = cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
    }
};
