#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(ll int n)  
{  
    // Corner cases  
    if (n <= 1)  return false;  
    if (n <= 3)  return true;  
    
    // This is checked so that we can skip   
    // middle five numbers in below loop  
    if (n%2 == 0 || n%3 == 0) return false;  
    
    for (ll int i=5; i*i<=n; i=i+6)  
        if (n%i == 0 || n%(i+2) == 0)  
           return false;  
    
    return true;  
} 
int nextPrime(ll int N) 
{ 
  
    // Base case 
    if (N <= 1) 
        return 2; 
  
    ll int prime = N; 
    bool found = false; 
  
    // Loop continuously until isPrime returns 
    // true for a number greater than n 
    while (!found) { 
        prime++; 
  
        if (isPrime(prime)) 
            found = true; 
    } 
  
    return prime; 
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll int d;
        cin>>d;
    
        if(d==1)
        {
            cout<<"6\n";
           continue;
        }
        if(d==2)
        {
            cout<<"15\n";
            continue;
        }
        ll int s;
        if(isPrime(d+1))
        s=d+1;
        else 
        s=nextPrime(d);
        ll int trd;
        if(isPrime(d+s))
        trd=d+s;
        else 
        trd=nextPrime(s+d);
        cout<<s*trd<<"\n";
    }
    return 0;
}