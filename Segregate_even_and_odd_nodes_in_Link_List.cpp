Segregate even and odd nodes in a Link List

Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

NOTE: Don't create a new linked list, instead rearrange the provided one.


Example 1:

Input: 
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 8,2,4,6 are the even numbers 
so they appear first and 17,15,9 are odd 
numbers that appear later.

Example 2:

Input:
N = 4
Link List:
1 -> 3 -> 5 -> 7

Output: 1 3 5 7

Explaination: There is no even number. 
So ne need for modification.

Your Task:
You do not need to read input or print anything. Your task is to complete the function divide() which takes N and head of Link List as input parameters and returns the head of modified link list. Don't create a new linked list, instead rearrange the provided one.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
1 ≤ Each element of the list ≤ 105
  
  Solution------------------------------------------
  
  //{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(N==1)    
            return head;
        int i=0;
        Node *cur=head, *fo, *fe, *preve, *prevo;
        if((cur->data)%2)
        {
            fo=cur;
            while(i<N && (cur->data)%2)
            {
                prevo=cur;
                cur=cur->next;
                i++;
            }
            if(i==N)    
                return head;
            fe=cur;
            preve=fe;
            i++;
            cur=cur->next;
        }
        else
        {
            fe=cur;
            while(i<N && !((cur->data)%2))
            {
                preve=cur;
                cur=cur->next;
                i++;
            }
            if(i==N)    
                return head;
            fo=cur;
            prevo=fo;
            i++;
            cur=cur->next;
        }
        head=fe;
        // cout<<fo->data<<endl;
        // return head;
        while(i<N)
        {
            if((cur->data)%2)
            {
                prevo->next=cur;
                prevo=cur;
                cur=cur->next;
                i++;
                while(i<N && (cur->data)%2)
                {
                    prevo=cur;
                    cur=cur->next;
                    i++;
                }
            }
            else
            {
                preve->next=cur;
                preve=cur;
                cur=cur->next;
                i++;
                while(i<N && !(cur->data)%2)
                {
                    i++;
                    preve=cur;
                    cur=cur->next;
                }
            }
        }
        preve->next=fo;
        prevo->next=NULL;
        return fe;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends
