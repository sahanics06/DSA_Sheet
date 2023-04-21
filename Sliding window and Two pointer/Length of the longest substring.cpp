/*
Given a string S, find the length of the longest substring without repeating characters.


Example 1:

Input:
S = "geeksforgeeks"
Output:
7
Explanation:
Longest substring is
"eksforg".
Example 2:

Input:
S = "abdefgabef"
Output:
6
Explanation:
Longest substring are
"abdefg" , "bdefga" and "defgab".
 

Your Task:
You don't need to take input or print anything. Your task is to complete the function longestUniqueSubsttr() which takes a string S as and returns the length of the longest substring.

 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(K) where K is constant.


Constraints:
1 ≤ |S| ≤ 105
It is guaranteed that all characters of the String S will be lowercase letters from 'a' to 'z'
*/

//  Solution with O(N^2) time complexity

class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        
        int n=s.length(), c=0, ans=1;
        string st="";
        for(int i=0; i<n; i++)
        {
            int arr[26]={0};
            for(int j=i; j<n; j++)
            {
                  if(arr[s[j]-'a']==0)
                    {
                        arr[s[j]-'a']=1;
                        ans=max(ans,j-i+1);
                    }
                    else
                    {
                        break;
                    }
            }
        }
        return ans;
    }
};

// Solution 2-   Using sliding window and two pointer. Time complexity O(N^2)

class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int i=0, j=0, ans=1;
        int n=s.length();
        int arr[26]={0};
        while(i<n)
        {
            if(arr[s[i]-'a']==1)
            {
                ans=max(ans, i-j);
                while(j<i && (s[i]-'a')!=(s[j]-'a')) // Here we have to make arr elements to 0 of those elements which are occuring before
                {                                    //the repeating character so that we can make substring from the character which repeated and
                    arr[s[j]-'a']=0;                 //not losing the unique element between these two repeated character.
                    j++;                             //example:- manishkuiarjoy , here we have to make arr elements of m a n i to 0 and take all the unique elements
                }                                    //after 3rd index.
                j++;
                arr[s[i]-'a']=1;
            }
            else
            {
                arr[s[i]-'a']=1;
            }
            i++;
        }
        ans=max(ans, i-j);
        return ans;
    }
};
