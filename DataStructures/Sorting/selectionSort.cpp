#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {23, 11, 88, 44};
    int n = 4;

    // Algorithm
    
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }


    for(auto x : arr){
        cout << x << " ";
    }

    return 0;
}