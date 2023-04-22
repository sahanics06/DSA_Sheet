/*
*/

//Solution using recursion. Time complexity O(N^2).

class Solution{
    public:
    void insert(vector<int>&arr, int tmp)
    {
        if(arr.size()==0 || arr[arr.size()-1]<=tmp)
            {
                arr.push_back(tmp);
                return;
            }
        int val=arr[arr.size()-1];
        arr.pop_back();
        insert(arr, tmp);
        arr.push_back(val);
        return;
    }
    void sor(vector<int>&arr)
    {
        if(arr.size()==1)
            return;
        int tmp=arr[arr.size()-1];
        arr.pop_back();
        sor(arr);
        insert(arr, tmp);
        return;
    }
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
    sor(arr);
    return arr;
    }
};

// Using mergeSort. O(NlogN)

class Solution{
    public:
    void merge(vector<int>&arr, int l, int m, int r)
    {
        vector<int>v;
        int ll=l, rl=m+1;
        while(ll<=m && rl<=r)
        {
            if(arr[ll]<=arr[rl])
            {
                v.push_back(arr[ll++]);
            }
            else
            {
                v.push_back(arr[rl++]);
            }
        }
        while(ll<=m)
        {
            v.push_back(arr[ll++]);
        }
        while(rl<=r)
        {
            v.push_back(arr[rl++]);
        }
        for(int i=0; i<v.size(); i++)
        {
            arr[l++]=v[i];
        }
        return ;
    }
    void mergesort(vector<int>&arr, int l, int r)
    {
        if(l<r)
        {
            int m=l+(r-l)/2;
            mergesort(arr, l, m);
            mergesort(arr, m+1, r);
            merge(arr, l, m, r);
        }
        return;
    }
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
    mergesort(arr, 0, n-1);
    return arr;
    }
};
