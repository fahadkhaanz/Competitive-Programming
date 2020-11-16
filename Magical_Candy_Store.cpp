//git pull --rebase origin master
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define wi(t) int t;cin>>t;while(t--)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi adj[N];
vi vis(N);
ll int gcd(ll int a, ll int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int tc=1;
void solve()
    { 
        ll int n;
        cin>>n;
        vl ar(n+1);
        fo(i,n) cin>>ar[i];
        bool lst=false,fst=false;
        if(ar[0]==1) fst=true;
        if(ar[n-1]==1) lst=true;
        ll int chef=0,chefu=0;
        vl a(n),b(n);
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
        if(fst)
        {
            a[0]=1;
            b[0]=0;
            for(int i=1;i<n;i++)
            {
                if(ar[i]%2==0) b[i]=(b[i-1]+ar[i])%mod,a[i]=(a[i-1]+0)%mod;
                else b[i]=(b[i-1]+ar[i]-1)%mod,a[i]=(a[i-1]+0)%mod;
            }
            int q;
            cin>>q;
            while(q--)
            {
                ll int r;
                cin>>r;
                r--;
               ll int sum=(((a[n-1])%mod)*(r/n))%mod;
               sum=(sum%mod+a[r%n]%mod)%mod;
               if(r!=0&&r%n==0)
               sum=sum-1;
               cout<<sum<<"\n";
              

            }
             return;
        }
        else if(lst)
        {
            if(ar[0]%2==0) a[0]=ar[0]%mod,b[0]=0;
            else a[0]=(ar[0]-1)%mod,b[0]=0;
            for(int i=1;i<n;i++)
            {
                if(i!=n-1)
                {
                    if(ar[i]%2==0) a[i]=(a[i-1]+ar[i])%mod,b[i]=(b[i-1]+0)%mod;
                    else a[i]=(a[i-1]+ar[i]-1)%mod,b[i]=(b[i-1]+0)%mod;
                }
                else
                {
                    a[i]=(a[i-1]+ar[i])%mod,b[i]=(b[i-1]+0)%mod;
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
           sum=(((a[n-1])%mod)*(rm%mod))%mod;
           rm=r%n;
          
           if(rm>=0)
           {
               sum=(((sum%mod+a[rm]%mod)%mod));
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
               if(ar[1]==1) a[0]=(ar[0]%mod-1)%mod,b[0]=0;
               else a[0]=(ar[0])%mod,b[0]=0;
           }
           else
           {
               if(ar[1]==1) a[0]=(ar[0])%mod,b[0]=0;
               else a[0]=(ar[0]%mod-1)%mod,b[0]=0;
           }
           for(int i=1;i<n;i++)
           {
               if(ar[i]==1)
               {
                   b[i]=(b[i-1]%mod+1)%mod;
                   a[i]=(a[i-1])%mod;
                   continue;
               }
               if(i==n-1)
               {
                   if(ar[i]%2==0) a[i]=(a[i-1]%mod+ar[i]%mod-1)%mod, b[i]=(b[i-1]%mod+1)%mod;
                   else a[i]=(a[i-1]%mod+ar[i]%mod)%mod,b[i]=(b[i-1]%mod);
                   continue;
               }
              
            if(ar[i]%2==0)
           {
               if(ar[i+1]==1) a[i]=(a[i-1]%mod+ar[i]%mod-1)%mod,b[i]=(b[i-1]%mod);
               else a[i]=(a[i-1]%mod+ar[i]%mod)%mod,b[i]=(b[i-1]%mod);
           }
           else
           {
               if(ar[i+1]==1) a[i]=(a[i-1]%mod+ar[i]%mod)%mod,b[i]=(b[i-1]%mod);
               else a[i]=(a[i-1]%mod+ar[i]%mod-1)%mod,b[i]=(b[i-1]%mod);
           }
           }
           
        }
        //  fo(i,n) cout<<a[i]<<" ";cout<<endl;
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
           sum=(((a[n-1])%mod)*(rm%mod))%mod;
           rm=r%n;
          
           if(rm>=0)
           {
               sum=(((sum%mod+a[rm]%mod)%mod));
           }
            if(!fst&&!lst&&rm==n-1&&ar[rm]%2==0) sum++;
            if(ar[rm]%2==0&&ar[rm+1]==1&&!fst&&!lst) sum+=1;
            if(rm!=n-1&&ar[rm]!=1&&ar[rm]%2!=0&&ar[rm+1]!=1&&!fst&&!lst) sum+=1;
            if(ar[rm-1]%2==0&&ar[rm]==1&&!lst) sum+=2;

           cout<<sum%mod<<"\n";
        }
        
    }

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    wi(t)
    {
      solve();
    }

    return 0;
}

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

void ipgraph(int n, int m){
    int i, u, v;
    while(m--){
        cin>>u>>v;
    u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void dfs(int u, int par){
    for(int v:adj[u]){
        if (v == par) continue;
        dfs(v, u);
    }
}





