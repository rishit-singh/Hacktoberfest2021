#include<iostream>
using namespace std;
#define ll long long

ll seive[10000005];
//By Brute Force
void prime_fact(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>2)
        cout<<n <<" ";
}

//Modififying seive for prime factorization
void createSieveForPF(){
    ll n=1000000;
    //step 1 Mark from 1 to 10^6 as i
    for(ll i=1;i<=n;i++){
        seive[i]=i;
    }
    for(ll i=2;i*i<=n;i++){
        //mark multiples of i if seive[i]=i
        if(seive[i]==i){
            for(ll j=i*i;j<=n;j+=i){
                if(seive[j]==j){
                    seive[j]=i;
                }
            }
        }
    }
}

void getFactorization(int x)
{
    while(x!=1)
    {
        cout<<seive[x]<<" ";
        x=x/seive[x];
    }
}

int main(){
    int n;
    cout<<"Enter a number to print all its prime factors: ";
    cin>>n;
    createSieveForPF();
    cout<<"By Brute Force: ";
    prime_fact(n);
    cout<<"\nBy seive: ";
    getFactorization(n);
    return 0;
}
