// Leetcode Problem: 198. House Robber
// Link : ( https://leetcode.com/problems/house-robber/ )
// Dynamic Programming Approach
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    // if there are no houses we can't rob any money
    if (nums.size() == 0)
        return 0;
    // if there is only one house we rob only that
    if (nums.size() == 1)
        return nums[0];
    // if there are only 2 house we rob the one that has maximum cash
    if (nums.size() == 2)
        return max(nums[0], nums[1]);

    // else we use dp approach
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[nums.size() - 1];
}

int main(int argc, char const *argv[])
{

    int n;
    cout << "Enter Size : ";
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        int el;
        cout << "Enter element : ";
        cin >> el;
        x.push_back(el);
    }

    cout << rob(x);
    return 0;
}
