/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
c
Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)   return head;
        int c=0;
        ListNode *dum=new ListNode(0);
        dum->next=head;
        ListNode *cur=dum, *pre=dum, *nex=dum;
        while(cur->next)
        {
            c++;
            cur=cur->next;
        }
        while(c>=k)
        {
            cur=pre->next;
            nex=cur->next;
            for(int i=1; i<k; i++)
            {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;

            }
            pre=cur;
            c-=k;
        }
        return dum->next;
    }
};
