/*
You are given a stack St. You have to reverse the stack using recursion.

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Your Task:

You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and returns the reversed stack.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= size of the stack <= 104
-109 <= Each element of the stack <= 109
Sum of N over all test cases doesn't exceeds 106
Array may contain duplicate elements. 
*/

//  Solution Using recursion

class Solution{
public:
    void insert(stack<int>&st, int tmp)
    {
        if(st.size()==0)
            {
                st.push(tmp);   
                return ;
            }
        int val =st.top();
        st.pop();
        insert(st, tmp);
        st.push(val);
        return;
    }
    void Reverse(stack<int> &st){
        if(st.size()==1)
            return ;
        int tmp=st.top();
        st.pop();
        Reverse(st);
        insert(st, tmp);
        return;
    }
};
