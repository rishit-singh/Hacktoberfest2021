


/*
cpp method
recurcive approach to find the sum of digit of a number 
*/


#include <bits/stdc++.h>
using namespace std;

 /*  a recursive function that returns the sum 
 of the digits of a given integer.
 */
int sumOfDigits(int n) {
    //if our number becomes 0 it will be our base case
    if(n==0){
        return 0;
    }
       //we are adding last digit int our ans
       // and making recurcive call for rest number
    int ans=sumOfDigits(n/10)+n%10;
  
    return ans; 

}
int main(){
    int num;
    cin>>num;
    cout<<sumOfDigits(num); //this fuction will return the sum of digits of a number
    return 0;
}


