#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static long long int isPerfectSquare(long long int n)
    {
        long long int a = sqrt(n);
        return (a * a == n);
    }
};
int main()
{
    long long int n;
    cin >> n;
    cout << Solution::isPerfectSquare(n) << endl;
    return 0;
}
