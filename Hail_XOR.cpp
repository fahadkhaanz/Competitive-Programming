#include<bits/stdc++.h>
using namespace std;
#define fo(i,size) for(int i=0;i<size;i++)
#define ll long long

#define pb push_back

#define all(x) x.begin(), x.end()

#define wi(t) int t;cin>>t;while(t--)

typedef vector<int>		vi;
typedef vector<ll>		vl;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}


const int mod = 1000000007;
const int N = 3e5, M = N;


vl dp[33];
vi vis(N);

void bits(ll int size,vl lists)
{
    for(int i=0;i<size;i++)
        {
            ll int x=lists[i];
            for(int j=30;j>=0;j--)
            {
                if(x&(1<<j))
                {
                    dp[j].push_back(i);
                }
            }
        }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    wi(t)
    {
        ll int size,x;
        cin>>size>>x;
        vl lists(size);
        fo(i,size) 
        cin>>lists[i];
        for(int i=0;i<33;i++)
         dp[i].clear();
        bits(size,lists);
        vl ok(31,0);
        
        for(int i=0;i<size-1;i++)
        {
            for(int j=30;j>=0;--j)
            {
                ll int sbit = (1<<j);

                if((lists[i]&sbit)==0) 
                continue;

                lists[i]=lists[i]^sbit;
                ll int in;

                ok[j]++;
                if(ok[j]<dp[j].size())
                {
                    in = dp[j][ok[j]++];
                }
                else in = size - 1;

                lists[in] =lists[in]^sbit;
                x--;
                
                if(x==0)
                break;
            }
            if(x==0)
            break;
        }    
            if(size==2)
            {
                if(x&1)
                {
                lists[size-1]=lists[size-1]^(1<<0);
                lists[size-2]=lists[size-2]^(1<<0);
                 }

            for(int i=0;i<size;i++)
            cout<<lists[i]<<" ";
            cout<<"\n";
            }

            else{
             for(int i=0;i<size;i++) 
             cout<<lists[i]<<" ";
             cout<<"\n";
             
            }
      
          
    }

    return 0;
}





