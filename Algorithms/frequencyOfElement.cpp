// CPP program to count frequencies of array items
#include <bits/stdc++.h>
using namespace std;

void countFreq(int arr[], int n)
{
    // using map to store frequences
	unordered_map<int, int> mp;

	// Traverse through array elements and
	// count frequencies
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;

	// Traverse through map and print frequencies
	for (auto x : mp)
		cout << x.first << " " << x.second << endl;
}

int main()
{
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	countFreq(arr, n);
	return 0;
}
