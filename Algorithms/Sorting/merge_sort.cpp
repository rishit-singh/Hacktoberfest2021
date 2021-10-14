#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int>left_arr,vector<int>right_arr)
{
    vector<int> result;
    while(!left_arr.empty() && !right_arr.empty())
    {
        if(left_arr.front()<right_arr.front())
        {
            result.push_back(left_arr.front());
            left_arr.erase(left_arr.begin());
        }
        else
        {
            result.push_back(right_arr.front());
            right_arr.erase(right_arr.begin());
        }
    }
    if(!left_arr.empty())
    {
        while(!left_arr.empty())
        {
            result.push_back(left_arr.front());
            left_arr.erase(left_arr.begin());
        }
    }
    if(!right_arr.empty())
    {
        while(!right_arr.empty())
        {
            result.push_back(right_arr.front());
            right_arr.erase(right_arr.begin());
        }
    }
    return result;

}
vector<int> merge_sort(vector<int>& arr,int start,int end)
{
    if(start>end)
    {
        return arr;
    }
    int mid=(start+end)/2;
    vector<int> left_arr=merge_sort(arr,0,mid-1);
    vector<int> right_arr=merge_sort(arr,mid,end);
    return merge(left_arr,right_arr);
}
int main()
{
    int size,value;
    cout<<"please enter array size:-";
    cin>>size;
    vector<int> arr;
    cout<<"please enter the values"<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>value;
        arr.push_back(value);
    }
    merge_sort(arr,0,size);
    for(auto value: arr)
    {
        cout<<value<<" ";
    }
}
