/*
Given a Binary Tree of size N, you need to find all the possible paths from root node to all the leaf node's of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3
Output: 1 2 #1 3 #
Explanation: 
All possible paths:
1->2
1->3

Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 10 20 40 #10 20 60 #10 30 #

Your Task:
Your task is to complete the function Paths() that takes the root node as an argument and return all the possible path. 
(All the path are printed '#' separated by the driver's code.)

Note: The return type
cpp: vector
java: ArrayList>
python: list of list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
1<=N<=103.
  */
// **********************************************************************************************************

// Solution using dfs. We do dfs and push val in vector and if isLeaf and push_back into ans, then will completion of 
// dfs call pop_back for new path

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
 bool isLeaf(Node *root)
 {
    if(root->left==NULL && root->right==NULL)
        return true;
    else
        return false;
 }
 void dfs(Node *root, vector<int>&tmp, vector<vector<int>>&ans)
 {
     if(!root)
        return;
     if(isLeaf(root))
     {
         tmp.push_back(root->data);
         ans.push_back(tmp);
         tmp.pop_back();
         return;
     }
     tmp.push_back(root->data);
     dfs(root->left, tmp, ans);
     dfs(root->right, tmp, ans);
     tmp.pop_back();
 }
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<int>tmp;
    vector<vector<int>>ans;
    dfs(root, tmp, ans);
    return ans;
    
}
