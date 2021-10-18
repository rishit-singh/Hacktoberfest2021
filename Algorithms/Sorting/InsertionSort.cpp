#include <bits/stdc++.h>
using namespace std;
 
void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
 
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i =0; i<n; i++)
	cin>>arr[i];
 
    insertionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}
