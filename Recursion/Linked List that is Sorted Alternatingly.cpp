/*
Given a Linked list of size N, the list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

 

Example 1:

Input:
LinkedList: 1->9->2->8->3->7
Output: 1 2 3 7 8 9
Explanation: After sorting the given
list will be 1-> 2-> 3-> 7-> 8-> 9.
 

Example 2:

Input:
LinkedList: 13->99->21->80->50
Output: 13 21 50 80 99
Explanation: After sorting the given list 
will be 12-> 21-> 50-> 80-> 99.
 

Your Task:
You do not need to read input or print anything. The task is to complete the function sort() which should sort the linked list in non-decreasing order. 

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= Number of nodes <= 100
0 <= Values of the linked list <= 103
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
void split(Node* head, Node** aHead, Node**  dHead)
{
    *aHead=new Node(0);
    *dHead=new Node(0);
    Node *cur=head;
    Node *as=*aHead, *dc=*dHead;
    while(cur)
    {
        as->next=cur;// everytime forget to move this pointer to next
        as=as->next;
        cur=cur->next;
        if(cur)
        {
            dc->next=cur;
            dc=dc->next;
            cur=cur->next;
        }
    }
    as->next=NULL;
    dc->next=NULL;
    *aHead=(*aHead)->next;
    *dHead=(*dHead)->next;
}
Node* merge(Node *head1, Node*head2)
{
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    Node* tmp=NULL;
    if(head1->data<head2->data)
    {
        tmp=head1;
        head1->next=merge(head1->next, head2);
    }
    else
    {
        tmp=head2;
        head2->next=merge(head1, head2->next);
    }
    return tmp;
}

void reverse(Node* &head)
{
    Node* cur=head, *prev=NULL, *tmp;
    while(cur)
    {
        tmp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }
    head=prev;
}
void sort(Node **head)
{
    Node *aHead, *dHead;
    split(*head, &aHead, &dHead);
    reverse(dHead);
    *head=merge(aHead, dHead);
}
