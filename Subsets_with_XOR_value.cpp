/* GFG
Given an array arr of N integers and an integer K, find the number of subsets of arr having XOR of elements as K.
 

Example 1:

Input:
N = 4
k = 6
arr: 6 9 4 2
Output:
2
Explanation:
The subsets are 
{4,2} and {6}
Example 2:

Input:
N = 5
K = 4
arr: 1 2 3 4 5
Output:
4
Explanation:
The subsets are {1, 5},
{4}, {1, 2, 3, 4},
and {2, 3, 5}

Your Task:
You don't need to read input or print anything. Your task is to complete the function subsetXORâ€‹() which takes the array arr[], its size N and an integer K as input parameters and returns the number of subsets having xor as K
 

Expected Time Complexity: O(N*M)
Expected Space Complexity: O(N*M)
Note: M = maximum value any XOR subset will acquire
 

Constraints:
1<=N<=20
1<=K<=100
0<=arr[i]<=100
*/

class Solution{
public:
    int dp[25][200]; // we took 25 because max value of N is 20 and 200 because max of arr[i]=100 and binary of 100 is 1100100 so max
                                                //of this bit is when all becomes 1 i.e 1111111 so 200 we have taken 180 will also work.
    int rec(vector<int> arr, int N, int K, int x, int i)
    {
        if(i==N)
        {
            if(x==K)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int ans=0;
        if(dp[i][x]!=-1)
        {
            return dp[i][x];
        }
        int a1= rec(arr, N, K, x^arr[i], i+1); // XOR done
        int a2= rec(arr, N, K, x, i+1); // XOR not done
        ans=a1+a2;
        dp[i][x]= ans;
        return ans;
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        memset(dp, -1, sizeof(dp));
        return rec(arr, N, K, 0, 0);
    }
};
