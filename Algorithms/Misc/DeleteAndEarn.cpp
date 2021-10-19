// Leetcode Problem : 740 Delete And Earn
// Link : (https://leetcode.com/problems/delete-and-earn/ )
#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int max_el = *max_element(nums.begin(), nums.end());
    vector<int> freq(max_el + 1, 0);
    vector<int> dp(max_el + 1, 0);

    // setting the frequency of each element
    for (const auto el : nums)
    {
        freq[el]++;
    }
    dp[1] = freq[1];
    dp[2] = max(dp[1], freq[2] * 2);
    // take either the previous element i.e the already calculated sum
    // or frequency*index of current element plus the previous to previous sum already calculated
    for (int i = 3; i <= max_el; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
    }
    return dp[max_el];
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
    cout << deleteAndEarn(x);
    return 0;
}
