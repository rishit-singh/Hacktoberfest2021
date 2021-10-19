#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int n = mid - start + 1;
    int m = end - mid;  
    int a[n]; // element's from start to mid-1;
    int b[m]; // element's from mid to end
    for(int i=0;i<n;i++){
        a[i] = arr[start + i];
    }
    for(int i=0;i<m;i++){
        b[i] = arr[mid + 1 + i];
    }
    int i=0, j=0, k=start;
    while(i < n && j < m){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }else{
            arr[k++] = b[j++];
        }
    }
    while(i < n){
        arr[k++] = a[i++];
    }
    while(j < m){
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[], int start, int end){
    // if start == end then only 1 element or start > end then no element
    // to start we need atleast 2 element
    if(start < end){ 
        int mid = (start+end)/2;
        mergeSort(arr, start, mid); // sort left half
        mergeSort(arr, mid+1, end); // sort right half
        merge(arr, start, mid, end); // merge two sorted array's
    }

}

int main(){
    int arr[] = {23, 44, 26, 99, 77};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}