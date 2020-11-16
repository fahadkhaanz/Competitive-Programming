#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vl vector<ll int>

vi pr;

const ll int mod = 4294967296;

void simple(int limit, vector<int> &prime)
{
    
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
    for (int p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
           
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            pr.push_back(p);
        }
    }
}
 
void Sieve(int n)
{
   
    int limit = floor(sqrt(n))+1;
    vector<int> prime; 
    simple(limit, prime); 
    int low = limit;
    int high = 2*limit;
    while (low < n)
    {
        if (high >= n) 
           high = n;
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (int i = 0; i < prime.size(); i++)
        {
          
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
            for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                pr.push_back(i);
 
        low = low + limit;
        high = high + limit;
    }
}



void A()
{
        ll int n;
        cin>>n;
        vl ar(n+1);
        map<ll int,ll int> mp;
        int j=0;
        for(int i=1;i<=n;i++) 
        {
            cin>>ar[i];
            if(mp[ar[i]]==0) 
            mp[ar[i]]=pr[j++];
        }
        for(int i=1;i<=n;i++)
        {
           cout<<mp[ar[i]]<<" ";
            
        }
        cout<<"\n";
}


void B()
{
        ll int n;
        cin>>n;
        vl ar(n+1);
        for(int i=0;i<n;i++)
         cin>>ar[i];
        bool last=false,first=false;
        if(ar[0]==1) 
            first=true;
        if(ar[n-1]==1) 
            last=true;
        
        vl chef(n),chefu(n);
        if(n==1)
        {   
            int q;
            cin>>q;
            while(q--)
            {
                ll int r;
                cin>>r;
              
                if(r==1)
                {
                    cout<<ar[0]%mod<<"\n";
                    continue;
                }
                if(ar[0]%2!=0)
               {
                cout<<(r*ar[0]%mod)%mod<<"\n";
               }
               else 
               { 
                r--;
                cout<<(((ar[0]-1)*r)%mod+ar[0]%mod)%mod<<"\n";
               }
            }
            return;
            
        }
        if(first)
        {
            chef[0]=1;
            chefu[0]=0;
            for(int i=1;i<n;i++)
            {
                if(ar[i]%2==0) chefu[i]=(chefu[i-1]+ar[i])%mod,chef[i]=(chef[i-1]+0)%mod;
                else chefu[i]=(chefu[i-1]+ar[i]-1)%mod,chef[i]=(chef[i-1]+0)%mod;
            }
            int q;
            cin>>q;
            while(q--)
            {
                ll int r;
                cin>>r;
                r--;
               ll int sum=(((chef[n-1])%mod)*(r/n))%mod;
               sum=(sum%mod+chef[r%n]%mod)%mod;
               if(r!=0&&r%n==0)
               sum=sum-1;
               cout<<sum<<"\n";
              

            }
             return;
        }
        if(last)
        {
            if(ar[0]%2==0) chef[0]=ar[0]%mod,chefu[0]=0;
            else chef[0]=(ar[0]-1)%mod,chefu[0]=0;
            for(int i=1;i<n;i++)
            {
                if(i!=n-1)
                {
                    if(ar[i]%2==0) chef[i]=(chef[i-1]+ar[i])%mod,chefu[i]=(chefu[i-1]+0)%mod;
                    else chef[i]=(chef[i-1]+ar[i]-1)%mod,chefu[i]=(chefu[i-1]+0)%mod;
                }
                else
                {
                    chef[i]=(chef[i-1]+ar[i])%mod,chefu[i]=(chefu[i-1]+0)%mod;
                }
                
            }
           int q;
          cin>>q;
        while (q--)
        {
           ll int r;
           cin>>r;
           r--;
           if(r==0)
           {
               cout<<ar[0]%mod<<"\n";
               continue;
           }
           ll int rm=(r)/n;
           ll int mnus=rm;
           ll int sum=0;
           sum=(((chef[n-1])%mod)*(rm%mod))%mod;
           rm=r%n;
          
           if(rm>=0)
           {
               sum=(((sum%mod+chef[rm]%mod)%mod));
           }
           if(ar[rm]%2!=0&&rm!=n-1) sum++;
           cout<<sum%mod<<"\n";
        }
         return;


        }
        
        else
        {  
           ar[n]=0;
           if(ar[0]%2==0)
           {
               if(ar[1]==1) chef[0]=(ar[0]%mod-1)%mod,chefu[0]=0;
               else chef[0]=(ar[0])%mod,chefu[0]=0;
           }
           else
           {
               if(ar[1]==1) chef[0]=(ar[0])%mod,chefu[0]=0;
               else chef[0]=(ar[0]%mod-1)%mod,chefu[0]=0;
           }
           for(int i=1;i<n;i++)
           {
               if(ar[i]==1)
               {
                   chefu[i]=(chefu[i-1]%mod+1)%mod;
                   chef[i]=(chef[i-1])%mod;
                   continue;
               }
               if(i==n-1)
               {
                   if(ar[i]%2==0) chef[i]=(chef[i-1]%mod+ar[i]%mod-1)%mod, chefu[i]=(chefu[i-1]%mod+1)%mod;
                   else chef[i]=(chef[i-1]%mod+ar[i]%mod)%mod,chefu[i]=(chefu[i-1]%mod);
                   continue;
               }
              
            if(ar[i]%2==0)
           {
               if(ar[i+1]==1) chef[i]=(chef[i-1]%mod+ar[i]%mod-1)%mod,chefu[i]=(chefu[i-1]%mod);
               else chef[i]=(chef[i-1]%mod+ar[i]%mod)%mod,chefu[i]=(chefu[i-1]%mod);
           }
           else
           {
               if(ar[i+1]==1) chef[i]=(chef[i-1]%mod+ar[i]%mod)%mod,chefu[i]=(chefu[i-1]%mod);
               else chef[i]=(chef[i-1]%mod+ar[i]%mod-1)%mod,chefu[i]=(chefu[i-1]%mod);
           }
           }
           
        }
        
        int q;
        cin>>q;
        while (q--)
        {
           ll int r;
           cin>>r;
           r--;
           if(r==0)
           {
               cout<<ar[0]%mod<<"\n";
               continue;
           }
           ll int rm=(r)/n;
           ll int mnus=rm;
           ll int sum=0;
           sum=(((chef[n-1])%mod)*(rm%mod))%mod;
           rm=r%n;
          
           if(rm>=0)
           {
               sum=(((sum%mod+chef[rm]%mod)%mod));
           }
            if(!first&&!last&&rm==n-1&&ar[rm]%2==0) sum++;
            if(ar[rm]%2==0&&ar[rm+1]==1&&!first&&!last) sum+=1;
            if(rm!=n-1&&ar[rm]!=1&&ar[rm]%2!=0&&ar[rm+1]!=1&&!first&&!last) sum+=1;
            if(ar[rm-1]%2==0&&ar[rm]==1&&!last) sum+=2;

           cout<<sum%mod<<"\n";
        }
        
}
#define N (int)3e5
vi adj[N];vi vis(N);vi path[N];



void graph(int node)
{
 
   
    queue<pair<int, int> > qu;
 
   
    qu.push({ node, -1 });

    vis[node] = true;
 
    while (!qu.empty()) 
    {

        pair<int, int> p = qu.front();
 
        
        qu.pop();

        vis[p.first] = true;
 
       
       
 
        for (int child : adj[p.first]) 
        {
            if (!vis[child]) 
            {
               
                qu.push({ child, p.first });
 
                path[child] = path[p.first];
                
                path[child].push_back(p.first);
            }
        }
    }
}



void C()
{
        
        ll int n,q;
       
        cin>>n>>q;
       
        vl ar(n);
       
        for(int i=0;i<n;i++) 
        
        cin>>ar[i],vis[i]=0;
        
        ll int m=n-1;
        
         while(m--)
         {        
                  int u,v;
                 
                  cin>>u>>v;
                 
                  u--, v--;
                
                 adj[u].push_back(v);
              
                 adj[v].push_back(u);
        }
        graph(0);
        
        while(q--)
        {
           
            int u,v;
           
            cin>>u>>v;
           
            u--,v--;
            
            vector<int> a=path[u];
            
            vector<int> b=path[v];
           
            a.push_back(u);
           
            b.push_back(v);
            
            ll int ans=0;
            
            int j=0;
           
            for(int i=0;i<a.size();i++)
            {   
               
                 ans=(ans+(ar[a[i]]%mod*ar[b[i]]%mod)%mod)%mod;
            
            } 
            
            cout<<ans<<"\n";
        }
}


int main()
{    
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int tc;
    // cin>>tc;
    // Sieve(4000000);
    // for(int test=1;test<=tc;test++)
    {
        // A();
        // B();
        C();
    }
    return 0;
}