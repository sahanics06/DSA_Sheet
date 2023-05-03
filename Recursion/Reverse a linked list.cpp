/*
Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
Your Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104
*/

// Efficient approach without recursion

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        // code here
        // return head of reversed list
        Node *cur=head, *tmp;
        Node*prev=NULL;
        while(cur)
        {
            tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
    
};

//Solution with return type Recursion

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *cur)
    {
        if(cur==NULL || cur->next==NULL)
        {
            return cur;
        }
        struct Node *tmp=reverseList(cur->next);
        cur->next->next=cur;
        cur->next=NULL;
        return tmp;
            
    }
    
};

// Same as above.
class Solution
{
    public:
    struct Node *rever(struct Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        struct Node *tmp=head;
        struct Node *newHead=rever(head->next);
        tmp->next->next=tmp;
        tmp->next=NULL;
        return newHead;
    }
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        return rever(head);
            
    }  
};

// Solution without return type
class Solution
{
    public:
    void rever(struct Node *cur, struct Node *prev, struct Node *&Head)
    {
        if(cur==NULL)
        {
            Head=prev;
            return;
        }
        rever(cur->next, cur, Head);
        cur->next=prev;
    }
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        struct Node* prev=NULL;
        rever(head, prev, head);
        return head;
            
    }
    
};
