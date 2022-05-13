#include <bits/stdc++.h>
using namespace std;
// using STL 
int MaxElement(int arr[], int n)
{
  int ans = *max_element(arr, arr + n);
  return ans;
}
int MinElement(int arr[], int n)
{
  int ans = *min_element(arr, arr + n);
  return ans;
}
int main()
{
  int n;
  cin >> n ;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << MaxElement(arr, n) << endl;
  cout << MinElement(arr, n) << endl;
  return 0;
}
