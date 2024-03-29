/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
*/

class Solution
{
    public:
    Node* rever(Node *head)
    {
        Node *cur=head, *prev=NULL, *tmp;
        while(cur)
        {
            tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *cur=rever(head);
        Node *ans=cur;
        int sum=1;
        while(sum && cur)
        {
            sum+=cur->data;
            cur->data=sum%10;
            sum=sum/10;
            cur=cur->next;
        }
        
        Node *tmp= rever(ans);
        if(sum)
        {
            Node *t=new Node(1);
            t->next=tmp;
            tmp=t;
        }
        return tmp;
    }
};
