/*phi(n)=find all numbers less than n such that gcd(numbers,n)=1*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll phi[1000005];

/*square root method  Time complexity - sqrt(n)
if n is prime then phi(n)=n-1
        else phi(n)=p^x-p^(x-1) 
        phi(32)=2^5-2^4*/ 
int euler_torent(int n){
    float ans=1.0;
    map<int,int>mp;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n=n/i;
            mp[i]++;
        }
    }
    if(n>=2)
        mp[n]++;
    for(auto it:mp){
        ans=ans*((pow(it.first,it.second)-(pow(it.first,it.second-1))));//phi(n)=p^x-p^x-1
    }
    return ans;
}

/*phi(n)=n*π(1-1/p) p=prime factors of n
    phi(36)=36(1-1/2)*(1-1/3) */
int meth_two(int n){
    float ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)
                 n=n/i;
            ans=ans*(1.0-(1.0/(float)i));
        }
    }
    if(n>=2)
        ans=ans*(1.0-(1.0/(float)n));
    return (int)ans;
}


void seiveForEuler(){
    ll n=1000000,j;
    phi[1]=0;
    for(int i=2;i<=n;i++){
        phi[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            j=1;
            while((i*j)<n){//traversing all multiples
                phi[i*j]=phi[i*j]-(phi[i*j]/i);
                j++;
            }
        }
    }
}

int main(){
    seiveForEuler();
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Methd 1: the total numbers are "<<euler_torent(n);
    cout<<"\nMethd 2: the total numbers are "<<meth_two(n);
    cout<<"\nMethd 3: the total numbers are "<<phi[n];
    return 0;
}