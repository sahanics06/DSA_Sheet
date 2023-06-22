/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with 
the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

// Solution using recursion and memoization

class Solution {
public:
    int solve(vector<int>&prices, int n, bool buy, int index, vector<vector<int>>&dp)
    {
        if(index>=n)
        {
            return 0;
        }
        int profit=0;
        if(dp[index][buy]!=-1)  return dp[index][buy];
        if(buy)
        {
            int taken=solve(prices, n, 0, index+1, dp)-prices[index];
            int not_taken=solve(prices, n, 1, index+1, dp);
            profit=max({profit, taken, not_taken});
        }
        else
        {
            int taken=prices[index]+solve(prices, n, 1, index+2, dp);
            int not_taken=solve(prices, n, 0, index+1, dp);
            profit=max({profit, taken, not_taken});
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        bool buy=true;
        vector<vector<int>>dp(5001, vector<int>(2,-1));
        return solve(prices, n, buy, 0, dp);
    }
};
