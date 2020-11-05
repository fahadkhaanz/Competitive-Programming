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

vi g[N];
int a[N];
ll int gcd(ll int a, ll int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int tc=1;
vi adj[N+1];
vi col(N+1),vis(N+1);
bool dfs1(int u,int c)
{
    vis[u]=1;
    col[u]=c;
    for(int i:adj[u])
    {
        if(vis[i]==0)
        {
            if(dfs1(i,c^1)==false)
            return false;
        }
        else 
        {
            if(col[i]==col[u])
            return false;
        }
    }
    return true;
}
void solve()
    {   
         cout<<"Scenario #"<<tc++<<":\n";
        int n,m;
        cin>>n>>m;
        
        // adj[N+1].clear();
        // adj[N+1].resize(n+1);
       // col.clear();
        // vis.clear();
        // col.resize(n+1);
        // vis.resize(n+1);
        for(int i=1;i<=n;i++) adj[i].clear(),vis[i]=0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bool f=true;
        for(int i=1;i<=n;i++)
        {   
            if(vis[i]==0)
            {
                    bool res=dfs1(i,0);
                    if(res==false)
                    f=false;
            }
           
            
           
        } 
      
        if(f==false)
        {
            cout<<"Suspicious bugs found!\n";
        }
        else
        {
           cout<<"No suspicious bugs found!\n";
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
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par){
    for(int v:g[u]){
        if (v == par) continue;
        dfs(v, u);
    }
}





