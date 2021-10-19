#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = (low + high)/2; 
    swap(arr[pivot], arr[high]); 
    int i=low;                  
    for(int j=low;j<high;j++){      
        if(arr[j] <= arr[high]){ 
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[high]);     
    return i;   
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
    int arr[] = {55, 44, 33, 22, 11};
    int low = 0;
    int high = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, low, high-1);
    for(auto x : arr){
        cout << x << " ";
    }
    return 0;
}