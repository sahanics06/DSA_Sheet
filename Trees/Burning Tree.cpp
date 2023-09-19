/*
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is 
set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and 
parent.
Note: The tree contains unique values.

Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as 
input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 104
*/

//*****************************************************************************************************
// Solution
/*
BFS to find the longest distance from source to leaf node. We have to keep track of visited node because when we go towards 
the parent then from parent node also it will traverse the left and right child thou the parent was invoked by child only. 
Also we have to find the parents for every child.
*/

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        queue<Node*>q;
        q.push(root);
        Node* source;
        unordered_map<Node*, Node*>mp;
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            if(node->data==target)
            {
                source = node;
            }
            if(node->left)
            {
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        queue<pair<Node*,int>>qq;
        int ans;
        vector<int>vis(10001,0);
        qq.push({source, 0});
        vis[source->data]=1;
        while(!qq.empty())
        {
            int n=qq.size();
            int dist = qq.front().second;
            ans=dist;
            while(n)
            {
                Node* node = qq.front().first;
                qq.pop();
                n--;
                if(node->left)
                {
                    if(vis[node->left->data]==0)
                    {
                        qq.push({node->left, dist+1});
                        vis[node->left->data]=1;
                    }
                }
                if(node->right)
                {
                    if(vis[node->right->data]==0)
                    {
                        qq.push({node->right, dist+1});
                        vis[node->right->data]=1;
                    }
                }
                if(mp.find(node)!=mp.end())
                {
                    Node* tmp = mp[node];
                    if(vis[tmp->data]==0)
                    {
                        qq.push({tmp, dist+1});
                        vis[tmp->data]=1;
                    }
                }
            }
        }
        return ans;
    }
};
