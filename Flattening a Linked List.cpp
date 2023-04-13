/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
 

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns the head of flattened link list.

Expected Time Complexity: O(N*N*M)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103
*/

Node *merge(Node *l1, Node *l2)
{
    Node *tmp=new Node(0);
    Node *ans=tmp;
    while(l1 && l2)
    {
        if(l1->data<=l2->data)
        {
            tmp->bottom=l1;
            tmp=tmp->bottom;
            l1=l1->bottom;
        }
        else
        {
            tmp->bottom=l2;
            tmp=tmp->bottom;
            l2=l2->bottom;
        }
    }
    while(l1)
    {
        tmp->bottom=l1;
        tmp=tmp->bottom;
        l1=l1->bottom;
    }
    while(l2)
    {
        tmp->bottom=l2;
        tmp=tmp->bottom;
        l2=l2->bottom;
    }
    return ans->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL)
   {
       return root;
   }
   root->next=flatten(root->next);
   root=merge(root, root->next);
   return root;
}
