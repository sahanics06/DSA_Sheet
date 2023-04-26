#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int>&arr, int i, int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<n && arr[l]>arr[largest])
	{
		largest=l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, largest, n);
	}
}
vector<int> buildHeap(vector<int> arr, int n)
{	
	for(int i=n/2; i>=0; i--)
	{
		heapify(arr, i, n); // In complete binary tree there are (n/2)+1 to nth nodes as leaf nodes. And leaf nodes are itself max heap or min heap..
	}                     // So we need to call heapify on 0th to n/2 node.
	return arr;

}
