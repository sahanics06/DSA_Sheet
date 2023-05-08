/*
Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected)
can be constructed out of a given n number of vertices.

Example 1:
Input: 2
Output: 2

Example 2:
Input: 5
Output: 1024

Your Task:
Complete the function count() which takes an integer n as input and return the count of total number of graphs possible.
Expected Time Complexity: O(1)
Expected Space Complexity: O(1)
Constraints:
1<=n<=10
*/

class Solution {
  public:
    long long count(int n) {
        // your code here        // A node can have maximum of N-1=X edges. So for graph with 0 edges is XC0, 1 edge is XC1, 2 edges XC2,...N-1 edges XCN-1.
        return 1LL<<(n*(n-1)/2); // So sum of coefficient of Binomial expansion is 2^X.
    }
};
