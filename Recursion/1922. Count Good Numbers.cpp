/*
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015
*/

// Solution using recursion
class Solution {
public:
    int mod=1e9+7;
    int rec(long long n, int x)
    {
        if(n==0)    return 1;
        long long ans=1;
        if(n%2)
        {
            ans=(rec(n-1, x))%mod;
            return (ans*x)%mod;
        }
        else
        {
            ans=rec(n/2,x)%mod;
            return (ans*ans)%mod;
        }
    }
    int countGoodNumbers (long long n) {
        long long even=(rec((n+1)/2, 5))%mod;
        long long odd=(rec(n/2, 4))%mod;
        return (even*odd)%mod;
    }
};

// Solution using recursion. x=20

class Solution {
public:
    int mod=1e9+7;
    int rec(long long n, int x)
    {
        if(n==0)    return 1;
        long long ans=1;
        if(n%2)
        {
            ans=(rec(n-1, x))%mod;
            return (ans*x)%mod;
        }
        else
        {
            ans=rec(n/2,x)%mod;
            return (ans*ans)%mod;
        }
    }
    int countGoodNumbers (long long n) {
        long long ans=rec(n/2, 20)%mod;
        return n%2?(ans*5)%mod:ans;
    }
};

//  Solution using while loop

class Solution {
public:
    int countGoodNumbers(long long n) {
        if(n==1)    return 5;
        int mod=1e9+7;
        int t=n;
        long long ans=1;
        long long x=20;
        n=n/2;
        while(n>0)
        {
            if(n%2==1)  
            {
                ans=(ans*x)%mod;
                n--;
            }
            else
            {
                x=(x*x)%mod;
                n=n/2;
            }            
            
        }
        if(t%2) ans=(ans*5)%mod;
        return ans;
    }
};