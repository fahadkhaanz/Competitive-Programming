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
vector<pair<ll,ll>> mep(100005);
vector<ll> check(100005,-1);
ll int ans=0;

void dfs(int i)
{
 vis[i]=1;
 for(auto u:adj[i])
 {
    
     if(vis[u]==0)
     {
       
     // cout<<i<<"-->"<<u<<"= "<<abs(check[i]-check[u])<<"\n";
       ans+=abs(check[i]-check[u]);  dfs(u);
     }
  // { }
 }
}


void solve()
    { 
        ll int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            vis[i]=0;
        }
        ans=0;
        mep.clear();
        fo(i,n)
        {
            cin>>mep[i+1].first>>mep[i+1].second;
        }
        fo(i,n-1)
        {
            ll int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()>1)
            {
                check[i]=(mep[i].first+mep[i].second)/2;
            }
        }
          for(int i=1;i<=n;i++)
        {
            if(adj[i].size()==1)
            {  
                ll int k;
                for(auto j:adj[i])
                k=check[j];
                if(abs(k-mep[i].first)>abs(k-mep[i].second))
                check[i]=mep[i].first;
                else
                check[i]=mep[i].second;
               // check[i]=(mep[i].first+mep[i].second)/2;
            }
           // cout<<check[i]<<" ";
        }//cout<<endl;
        dfs(1);
       
         
        cout<<ans<<"\n";

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





