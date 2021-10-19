#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a, int n){
    for(int i = 0; i < n; i++){             // for every element
        for(int j = 0; j < n-i-1; j++){     // j < n-i-1 -> comparing j with j+1 
            if(a[j] > a[j+1]){              // place greatest elemnet to the left
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main(){
    vector<int> a = {43, 88, 34, 23, 99, 54};
    int n = a.size();
    bubbleSort(a, n);
    for(int x : a){
        cout << x << " ";
    }
    return 0;
}