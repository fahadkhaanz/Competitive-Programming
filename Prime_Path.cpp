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

vi g[N],dis(N),vis(N),prime(N);
int a[N];
ll int gcd(ll int a, ll int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int tc=1;
bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
bool isvalid(int a,int b)
{
    string s1=to_string(a);
    string s2=to_string(b);
    int c=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i]) c++;
    }
    if(c==1) return true;
    else return false;
}
void buildgraph()
{
    for(int i=1000;i<=9999;i++)
    {
        if(isprime(i)) prime.pb(i);
    }
    for(int i=0;i<prime.size();i++)
    {
        for(int j=i+1;j<prime.size();j++)
        {
            if(isvalid(prime[i],prime[j]))
            {
                g[prime[i]].pb(prime[j]);
                g[prime[j]].pb(prime[i]);
            }
        }
    }
}
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node]=1;
    dis[node]=0;
    while(!q.empty())
    {
        int child=q.front();
        q.pop();
        vis[child]=1;
        for(auto i:g[child])
        {
            if(vis[i]==0)
            {
                q.push(i);
                dis[i]=dis[child]+1;
                vis[i]=1;
            }
        }
    }
}
void solve()
    { 
        int a,b;
        cin>>a>>b;
        for(int i=1000;i<=9999;i++) vis[i]=0,dis[i]=-1;
        dis.clear();
        bfs(a);
        if(dis[b]==-1)
        {
            cout<<"Impossible\n";
        }
        else
        {
            cout<<dis[b]<<"\n";
        }
        
    }

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
       prime.clear();
        buildgraph();
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





