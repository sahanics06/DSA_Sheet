/*
Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000
*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node * rever(Node * head)
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
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *fl, *sl;
        fl= rever(first);
        sl= rever(second);
        int sum=0;
        Node *tmp= new Node(0), *ans;
        ans=tmp;
        while(fl && sl)
        {
            sum+=fl->data+sl->data;
            tmp->next= new Node(sum%10);
            tmp=tmp->next;
            sum=sum/10;
            fl=fl->next;
            sl=sl->next;
            
        }
        if(sum && !fl && !sl)
        {
            tmp->next=new Node(1);
        }
        else if(fl && !sl)
        {
            while(sum && fl)
            {
                sum+=fl->data;
                tmp->next= new Node(sum%10);
                tmp=tmp->next;
                sum=sum/10;
                fl=fl->next;
                
            }
            if(sum && !fl)
            {
                tmp->next= new Node(1);
            }
            else if(fl)
            {
                tmp->next=fl;
            }
        }
        else if(!fl && sl)
        {
            while(sum && sl)
            {
                sum+=sl->data;
                tmp->next= new Node(sum%10);
                tmp=tmp->next;
                sum=sum/10;
                sl=sl->next;
                
            }
            if(sum && !sl)
            {
                tmp->next= new Node(1);
            }
            else if(sl)
            {
                tmp->next=sl;
            }
        }
        //while(sum)
        return rever(ans->next);
    }
};
