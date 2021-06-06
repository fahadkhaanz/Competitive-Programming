#include<bits/stdc++.h>
const int mod = 1000000007;
#define ll long long 
using namespace std;
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
int main()
{
    
    int t;
    cin>>t;
    while (t--)
    {   
        long long int ans=1;
        long long  int n,x;
        cin>>n>>x;
        for(int i=1;i<sqrt(n);i++)
        {
            if(n%i==0)
            {   
                if(n/i==i)
                ans=(ans%mod*mpow(i,x)%mod)%mod;
                else
                {
                    ans=((ans%mod*mpow(i,x)%mod)%mod*mpow(n/i,x))%mod;
                }
            }
        }
        cout<<ans<<"\n";
     
    }
    
}