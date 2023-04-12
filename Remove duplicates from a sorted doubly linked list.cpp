/*
Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

Example 1:

Input:
n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is 
retained, rest nodes with value = 1 are deleted.
Example 2:

Input:
n = 7
1<->2<->2<->3<->3<->4<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of nodes with values 2,3 and 4 are 
retained, rest repeating nodes are deleted.
Your Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

Constraint:
1 <= n <= 105
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if(head->next==NULL)    return head;
        Node *cur=head, *ans=head;
        while(cur->next)
        {
            int t=cur->data;
            while(cur->next && cur->next->data==t)
            {
                cur=cur->next;
            }
            if(cur->next==NULL)
            {
                ans->next=NULL;
                return head;
            }
            ans->next=cur->next;
            cur->next->prev=ans;
            ans=ans->next;
            cur=cur->next;
        }
        ans->next=NULL;
        return head;
    }
};
