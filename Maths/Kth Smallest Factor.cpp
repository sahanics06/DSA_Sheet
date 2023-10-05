/*
GIven two positive integers N and K. You have to find the Kth smallest factor of N. A factor of N is a positive integer which divides N. Output the Kth smallest 
factor of N if it exists otherwise print -1.

Example 1:

Input : N = 4 , K = 2
Output: 2
Explanation:
All factors of 4 are 1,2 and 4. Out of
these 2 is the 2nd smallest.
Example 2:

Input : N = 4 , K = 3
Output: 4
Explanation:
All factors of 4 are 1,2 and 4. Out of
these 4 is the 3rd smallest.
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function kThSmallestFactor() which takes 2 Integers N and K as input and returns the answer.

Expected Time Complexity: O(sqrt(N))
Expected Auxiliary Space: O(1) 

Constraints:
1 <= N <= 106
1 <= K <= 106

*/

//**********************************************************************************************************************************

// Solution

// Here we are creating two vectors forward and backward. In forward we keep i and N/i in backward

class Solution {
  public:
    int kThSmallestFactor(int N , int K) {
        vector<int>forward, backward;
        for(int i=1; i<=sqrt(N); i++)
        {
            if(N%i==0)
            {
                forward.push_back(i);
                if(i!=sqrt(N))
                {
                    backward.push_back(N/i);
                }
            }
        }
        reverse(backward.begin(), backward.end());
        if((forward.size()+backward.size())<K)
            return -1;
        if(forward.size()>=K)
            return forward[K-1];
        return backward[K-forward.size()-1];
    }
};
