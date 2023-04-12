/*
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

 

Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
 

Example 2:

Input: 
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPairsWithGivenSum() which takes head node of the doubly linked list and an integer target as input parameter and returns an array of pairs. If there is no such pair return empty array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 105
1 <= target <= 105
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>>v;
        if(!head && !head->next)
            return v;
        Node *l=head, *r=head;
        int i=0, c=0;
        while(r->next)
        {
            r=r->next;
            c++;
        }
        int sum=0;
        while(i<c)
        {
            sum=l->data+r->data;
            if(sum==target)
            {
                v.push_back({l->data, r->data});
                l=l->next;
                r=r->prev;
                i++;
                c--;
            }
            else if(sum>target)
            {
                r=r->prev;
                c--;
            }
            else
            {
                l=l->next;
                i++;
            }
        }
        return v;
        
    }
};
