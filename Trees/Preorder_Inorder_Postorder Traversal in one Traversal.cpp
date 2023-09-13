//Preorder, Inorder, and Postorder Traversal in one Traversal

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

// Solution

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>inOrder, preOrder, postOrder;
    stack<pair<TreeNode*,int>>st;
    st.push({root, 1});
    while(!st.empty())
    {
        TreeNode *tmp=st.top().first;
        int t=st.top().second;
        st.pop();
        if(t==1)
        {
            preOrder.push_back(tmp->data);
            st.push({tmp, t+1});
            if(tmp->left)
            {
                st.push({tmp->left, 1});
            }
        }
        else if(t==2)
        {
            inOrder.push_back(tmp->data);
            st.push({tmp, t+1});
            if(tmp->right)
            {
                st.push({tmp->right, 1});
            }
        }
        else
        {
            postOrder.push_back(tmp->data)    ;
        }        
    }
    ans.push_back(inOrder);
    ans.push_back(preOrder);
    ans.push_back(postOrder);
    return ans;
}
