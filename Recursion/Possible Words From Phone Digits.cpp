/*
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.


Example 1:

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi 
bdg bdh bdi beg beh bei bfg bfh bfi 
cdg cdh cdi ceg ceh cei cfg cfh cfi 
Explanation: When we press 2,3,4 then 
adg, adh, adi, ... cfi are the list of 
possible words.
Example 2:

Input: N = 3, a[] = {3, 4, 5}
Output:
dgj dgk dgl dhj dhk dhl dij dik dil 
egj egk egl ehj ehk ehl eij eik eil 
fgj fgk fgl fhj fhk fhl fij fik fil
Explanation: When we press 3,4,5 then 
dgj, dgk, dgl, ... fil are the list of 
possible words.
Your Task:
You don't need to read input or print anything. You just need to complete the function possibleWords() that takes an array a[ ] and N as input parameters and returns an array of all the possible words in lexicographical increasing order. 

Expected Time Complexity: O(4N * N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 10
2 ≤ a[i] ≤ 9
*/

class Solution
{
    public:
    void solve(vector<string>a, vector<char>b, vector<string>&ans)
    {
        for(int i=0; i<a.size(); i++)
        {
            for(int j=0; j<b.size(); j++)
            {
                string t=a[i];
                t+=b[j];
                ans.push_back(t);
            }
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        vector<vector<char>>key;
        vector<string>ans;
        key.push_back({'a','b','c'});
        key.push_back({'d','e','f'});
        key.push_back({'g','h','i'});
        key.push_back({'j','k','l'});
        key.push_back({'m','n','o'});
        key.push_back({'p','q','r','s'});
        key.push_back({'t','u','v'});
        key.push_back({'w','x','y','z'});
        vector<string>tmp;
        if(N==1)
        {
            for(int i=0; i<key[a[0]-2].size(); i++)
            {
                string t="";
                t+=key[a[0]-2][i];
                ans.push_back(t);
            }
            return ans;
        }
        for(int i=0; i<key[a[0]-2].size(); i++)
        {
            vector<char>t=key[a[0]-2];
            string s="";
            s+=t[i];
            tmp.push_back(s);
        }
        for(int i=1; i<N; i++)
        {
            ans.clear();
            solve(tmp, key[a[i]-2], ans);
            tmp=ans;
        }
        return ans;
    }
};
