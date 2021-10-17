#include <bits/stdc++.h>
using namespace std;
// In the worst Case time complexity is O(n^2) and in best case it is O(n);
void BubbleSort(int arr[],int n)
{
     for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
    
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

  BubbleSort(arr,n);
  printArray(arr,n);
   
    return 0;
}
