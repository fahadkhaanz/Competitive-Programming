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

int overlap(vector<pair<ll int, ll int> > v)
{
    // variable to store the maximum
    // count
    ll int ans = 0;
    ll int count = 0;
    vector<pair<ll int, char> > data;
 
    // storing the x and y
    // coordinates in data vector
    for (ll int i = 0; i < v.size(); i++) {
 
        // pushing the x coordinate
        data.push_back({ v[i].first, 'x' });
 
        // pushing the y coordinate
        data.push_back({ v[i].second, 'y' });
    }
 
    // sorting of ranges
    sort(data.begin(), data.end());
 
    // Traverse the data vector to
    // count number of overlaps
    for (ll int i = 0; i < data.size(); i++) {
 
        // if x occur it means a new range
        // is added so we increase count
        if (data[i].second == 'x')
            count++;
 
        // if y occur it means a range
        // is ended so we decrease count
        if (data[i].second == 'y')
            count--;
 
        // updating the value of ans
        // after every traversal
        ans = max(ans, count);
    }
 
    // printing the maximum value
   return ans;
}
void solve()
    { 
        ll int n;
        cin>>n;
        map<ll,vector<pair<ll,ll>>> mep;
        map<ll,ll> cnt;
        // vl l(n),r(n),v(n);
        for(int i=0;i<n;i++)
        {
            ll int l,r,s;
            cin>>l>>r>>s;
            mep[s].push_back({l,r});
        
        }
        
        for(auto i:mep)
        {   
            vector<pair<ll,ll>> ar=i.S;
            if(overlap(ar)>=3) {cout<<"NO\n";return;}
        }
       
        cout<<"YES\n";
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





