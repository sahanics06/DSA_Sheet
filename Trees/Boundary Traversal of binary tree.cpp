/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always 
travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you 
could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already 
included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Example 2:

Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8

Your Task:
This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input 
and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

// Solution

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node *root)
    {
        if(root->left==NULL && root->right==NULL)
            return true;
        else
            return false;
    }
    void solve_left(Node *root, vector<int>&ans)
    {
        Node *cur = root->left;
        while(cur)
        {
            if(!isLeaf(cur))
            {
                ans.push_back(cur->data);
            }
            if(cur->left)
                cur=cur->left;
            else
                cur=cur->right;
        }
        return ;
    }
    
    void solve_leaf(Node *root, vector<int>&ans)
    {
        if(root==NULL)
            return ;
        if(isLeaf(root))
            ans.push_back(root->data);
        solve_leaf(root->left, ans);
        solve_leaf(root->right, ans);
    }
    
    void solve_right(Node *root, vector<int>&ans)
    {
        stack<int>st;
        Node *cur=root->right;
        while(cur)
        {
            if(!isLeaf(cur))
            {
                st.push(cur->data);
            }
            if(cur->right)
                cur=cur->right;
            else
                cur=cur->left;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(!root)   return ans;
        if(!isLeaf(root))
            ans.push_back(root->data);
        solve_left(root, ans);
        solve_leaf(root,ans);
        solve_right(root,ans);
        return ans;
    }
};
