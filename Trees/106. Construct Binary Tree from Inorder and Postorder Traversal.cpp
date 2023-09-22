/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder 
traversal of the same tree, construct and return the binary tree.

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode* solve(vector<int>& postorder, int posStart, int posEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>&mp)
    {
        if(inStart>inEnd || posStart>posEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[posEnd]);
        int inRoot = mp[root->val];
        int node_left = inRoot-inStart;

        //Same as construct Binary Tree using inorder and preorder but here we take root value from posEnd.
        // here we can see for left subtree array taken is from posStart to posStart+node_left-1, we habe to subtract 1
        root->left = solve(postorder,posStart, posStart+node_left-1, inorder, inStart, inRoot-1, mp);
        root->right = solve(postorder, posStart+node_left, posEnd-1, inorder, inRoot+1, inEnd, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};
