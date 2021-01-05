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

vl dp(4005);
int dp1[4005][4005],dp2[4005][4005];
ll int n,k;
bool f=0;
ll int findans(int i,ll int sum1,ll int sum2,vl ar)
{  
    // deb2(sum1,sum2);
   

    if((sum1>=k and sum2>=k)) 
    {   
       
        return i;
    }
    if(i>=n) {return LONG_MAX;}
    
    if(sum1>=k)
    {   
        if(dp2[sum2][i]==-1)
        dp2[sum2][i]=findans(i+1,sum1,ar[i]+sum2,ar);
        return dp2[sum2][i];
    }
    if(sum2>=k)
    {  
        if(dp1[sum1][i]==-1)
        dp1[sum1][i]=findans(i+1,sum1+ar[i],sum2,ar);
        return dp1[sum1][i];
    }
        if(dp2[sum2][i]==-1)
        dp2[sum2][i]=findans(i+1,sum1,ar[i]+sum2,ar);
        if(dp1[sum1][i]==-1)
        dp1[sum1][i]=findans(i+1,sum1+ar[i],sum2,ar);
        return dp2[sum2][i]=dp1[sum1][i]=min(dp2[sum2][i],dp1[sum1][i]);

    
}
void solve()
    {  
        ll int sum1=0,sum2=0;
        cin>>n>>k;
        vl ar(n);
        fo(i,n) cin>>ar[i],dp[i]=-1;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<n;j++) dp1[i][j]=-1,dp2[i][j]=-1;
        }
        sort(all(ar),greater<ll>());
        
        ll int ans=findans(0,0,0,ar);
        if(ans!=LONG_MAX) 
        {
           cout<<ans<<"\n";
        }
        else
        {
             cout<<"-1\n";
             
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





