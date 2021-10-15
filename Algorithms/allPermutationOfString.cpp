#include <bits/stdc++.h>
using namespace std;
/*
recurcive algorithm to print permutation of string 
*/

void FindPermutations(string input, string ans)
{
    if (input.size() == 0)
    {
        cout << ans << endl;
        return;
    }
        // this  loop will place every character of string in
        // first place of our answer string 
    for (int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        string left_str = input.substr(0, i);
        string right_str = input.substr(i + 1);
        string rest = left_str + right_str;
        FindPermutations(rest, ans + ch); //recursive call for rest string
    }
}

int main()
{
    string s;
    cin >> s;
    string ans = "";//empty string to store answer character
    FindPermutations(s, ans);  //this fuction will print our permutation
    return 0;
}