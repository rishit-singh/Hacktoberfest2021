#include<bits/stdc++.h>
using namespace std;
bool is_palindrom(string str)
{
    int start=0;
    int end=str.length()-1;
    while(start<end)
    {
        if(str[start]==str[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;

}
int main()
{
    string str;
    cout<<"please enter string:-";
    cin>>str;
    cout<<is_palindrom(str);

}
