/*
*/

//Solution using recursion

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
