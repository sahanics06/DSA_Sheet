/* GFG
Given an array A[] of N integers and an integer X. The task is to find the sum of three integers in A[] such that it is closest to X.
Example 1:

Input:
N = 4
A[] = {-1 , 2, 1, -4}
X = 1
Output: 2
Explaination: 
Sums of triplets:
(-1) + 2 + 1 = 2
(-1) + 2 + (-4) = -3
2 + 1 + (-4) = -1
2 is closest to 1.

Example 2:

Input:
N = 5
A[] = {1, 2, 3, 4, -5}
X = 10
Output: 9
Explaination: 
Sums of triplets:
1 + 2 + 3 = 6
2 + 3 + 4 = 9
1 + 3 + 4 = 7
...
9 is closest to 10.

Your Task:
You don't need to read input or print anything. Your task is to complete the function closest3Sum() which takes the array Arr[] 
and its size N and X as input parameters and returns the sum which is closest to X.

NOTE: If there exists more than one answer then return the maximum sum.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
3 ≤ N ≤ 103
-103 ≤ Arr[i] ≤ 103
-104 ≤ X ≤ 104
  */

class Solution{
    public:
    int closest3Sum(int a[], int n, int x)
    {
        // code here
        int sum=0;
        int ans=INT_MAX;
        int i=0,j=0, h=n-1;
        sort(a,a+n);
        int l,r;
        for(int i=0; i<n; i++)
        {
            l=i+1, r=n-1;
            sum=0;
           while(l<r)
           {
               sum=a[i]+a[l]+a[r];
                    if(abs(x-sum)<abs(x-ans))
                    {
                        ans=sum;
                    }
                    // else if(abs(x-sum)==abs(x-ans))
                    // {
                    //     ans=sum>ans?sum:ans;
                    // }
                if(sum>x)
                {
                    r--;
                }
                else
                {
                    l++;
                }
                sum=0;
           }
        }
        return ans;
    }
};
