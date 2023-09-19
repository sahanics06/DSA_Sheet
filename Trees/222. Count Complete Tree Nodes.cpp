/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in 
the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
*/

//***************************************************************************************************************
//Solution by finding the height of left subtree and right subtree. If lh==rh then we return (1<<lh)-1. i.e, 2^lh-1 as number of nodes

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
    int count_lh(TreeNode* root)
    {
        if(!root)
            return 0;
        int i=0;
        while(root)
        {
            i++;
            root=root->left;
        }
        return i;
    }
    int count_rh(TreeNode* root)
    {
        if(!root)
            return 0;
        int i=0;
        while(root)
        {
            i++;
            root=root->right;
        }
        return i;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh = count_lh(root);// here we have to send root and not root->left
        int rh = count_rh(root);// because we have to find the height of whole subtree from root
        if(lh==rh)
            return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
