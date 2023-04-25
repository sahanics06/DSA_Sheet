/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
*/

void insert(stack<int>&st, int tmp)
{
    if(st.size()==0 || st.top()<=tmp)
    {
        st.push(tmp);
        return;
    }
    int val=st.top();
    st.pop();
    insert(st, tmp);
    st.push(val);
    return;
}
void SortedStack :: sort()
{
    if(s.size()==1)
        return ;
    int tmp=s.top();
    s.pop();
    sort();
    insert(s, tmp);
    return ;
   //Your code here
}
