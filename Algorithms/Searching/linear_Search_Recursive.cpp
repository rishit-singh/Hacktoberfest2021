#include<iostream>
using namespace std;

int search(int arr[],int l,int r,int x){
	if(l>r)//indicates elements not found
		return -1;
	if(arr[l]==x)//return index l if element found at that index
		return l;
	if(arr[r]==x)//return index r if element found at that index
		return r;
	return search(arr,l+1,r-1,x);//increment l by 1 and decrement r by 1 to search for other positions
}

int main(){
	int n;
	cout<<"Enter the limit of array:";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements:";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int x;
	cout<<"Enter the element to be searched:";
	cin>>x;
	int index=search(arr,0,n-1,x);
	if(index!=-1){
		cout<<"Element is present at index "<<index+1;
	}
	else
		cout<<"Element not present!!";
	return 0;
	
}
