/*
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. 
That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
 
Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.

*/

//*********************************************************************************

// Solution using sliding window , when there is repeatation of character then count++ and move the j pointer

class Solution {
public:
    int partitionString(string s) {
        int ans=1, n=s.length(), i=0, j=0;
        int arr[26]={0};
        while(i<n)
        {
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']>1)
            {
                ans++;
                while(j<i)
                {
                    arr[s[j]-'a']--;
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};
