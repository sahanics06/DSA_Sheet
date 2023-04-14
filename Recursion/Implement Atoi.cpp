/*
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt function.

Example 1:

Input:
str = 123
Output: 123
Example 2:

Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.
Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns -1.
Note: Numerical strings are the string where either every character is in between 0-9 or where the first character is '-'and the rest all characters are in between 0-9.

Expected Time Complexity: O(|S|), |S| = length of string str.
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length of S ≤ 10


Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, 
and not to write the full code.
*/

class Solution{
  public:
    /*You are required to complete this method */
    int rec(string s, int n)
    {
        if(n==1)
            return s[0]-'0';
        return 10*rec(s,n-1)+s[n-1]-'0';
        
    }
    int atoi(string str) {
        //Your code here
        int f=0;
        string tmp;
        int i=0;
        if(str[0]=='-')
        {
            i++;
            f=1;
        }
        for(i; i<str.length(); i++)
        {
            if(!isdigit(str[i]))
                return -1;
        }
        if(f)
        {
            tmp=str.substr(1);
        }
        //cout<<tmp[0]<<endl;
        if(f==1)
            return -1*rec(tmp, tmp.length());
        return rec(str, str.length());
    }
};
