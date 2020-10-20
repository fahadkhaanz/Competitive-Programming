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
int dp[100000];
bool f=false;
bool sol(int ar[],int n,int i)
{   
    if(i>=n||i<0) return 0;
    
   
    if(ar[i]==0)
    {   
        
      return 1;
        
    }
    if(dp[i]==1) return 0;
    dp[i]=1;
    if(i+ar[i]>=0&&i+ar[i]<n&&i-ar[i]>=0&&i-ar[i]<n)
    {   
        // if(dp[i+ar[i]]==-1)   dp[i+ar[i]]=sol(ar,n,i+ar[i]);
        // if(dp[i-ar[i]]==-1)   dp[i-ar[i]]=sol(ar,n,i-ar[i]);
        return (sol(ar,n,i+ar[i])||sol(ar,n,i-ar[i]));
    //    return dp[i]=(dp[i+ar[i]]||dp[i-ar[i]]);
    }
   else if(i+ar[i]>=0&&i+ar[i]<n)
    {   
        return sol(ar,n,i+ar[i]);
        // if(dp[i+ar[i]]==-1) dp[i+ar[i]]=sol(ar,n,i+ar[i]);
        // return dp[i]=dp[i+ar[i]];
        
    }
     else if(i-ar[i]>=0&&i-ar[i]<n)
    {    
        return sol(ar,n,i-ar[i]);
        // if(dp[i-ar[i]]==-1)   dp[i-ar[i]]=sol(ar,n,i-ar[i]);
        // return dp[i]=dp[i-ar[i]];
    }
    else 
    return 0;
   
   
    
    
}
void solve()
    { 
      int n;
      cin>>n;
      int ar[n];
      fo(i,n) cin>>ar[i];
      int k;
      cin>>k; 
      memset(dp,-1,sizeof(dp));
      if(sol(ar,n,k))
      cout<<"true"<<"\n";
      else 
      cout<<"false";
    }

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // wi(t)
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





