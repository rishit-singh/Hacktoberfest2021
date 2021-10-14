#include <bits/stdc++.h>
using namespace std;
void solve(string input, string ans)
{
    if (input.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        string left_str = input.substr(0, i);
        string right_str = input.substr(i + 1);
        string rest = left_str + right_str;
        solve(rest, ans + ch);
    }
}

int main()
{
    string s;
    cin >> s;
    string ans = "";
    solve(s, ans);
    return 0;
}