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
int lowerbound(vector<ll> arr,ll int X)
{
    ll int n=arr.size();
    ll int mid;
    ll int low = 0;
    ll int high = n;
    int ans=-1;
    while(low<high)
    {
          mid = low + (high - low) / 2;
          if(arr[mid]<=X)
          {
              ans=mid;
              low=mid+1;
          }
          else
          {
              high=mid-1;
          }
    }
    return ans;
}
 
// Function to implement upper_bound
int upperbound(vector<ll> arr,ll int X)
{
    ll int n=arr.size();
    ll int mid;
    ll int low = 0;
    ll int high = n;
     int ans=-1;
    while(low<high)
    {
          mid = low + (high - low) / 2;
          if(arr[mid]>X)
          {
                ans=mid;
               high=mid-1;
             
          }
          else
          {
              low=mid+1;
          }
    }
    return ans;
}
void solve()
    {   
         cout<<"Case #"<<tc++<<": ";
        ll int n,m;
        cin>>n>>m;
        set<ll> st1;
        for(int i=0;i<n;i++)
        {
            ll int a,b;
            cin>>a>>b;
            for(ll int j=a;j<=b;j++) st1.insert(j);
        }
        vector<ll> st;
        for(auto i:st1) st.push_back(i);
        vector<ll int> ans;
        vector<ll> vis(10005);
       // sortall(st);
        for(int i=0;i<m;i++)
        {
            ll int k;
            cin>>k;
            ll int diff=LONG_MAX;
            ll int l=lowerbound((st),k);
            ll int r=upperbound((st),k);
            // deb2(l,r);
            if(l==-1) l=r;
            if(r==-1) r=l;
            if(abs(st[l]-k)<=abs(st[r]-k))
            {
                 ans.push_back(st[l]);
                 st.erase(st.begin()+l);
            }
            else
            {
                  ans.push_back(st[r]);
                  st.erase(st.begin()+r);
            }

        }
        for(auto i:ans) cout<<i<<" ";
        cout<<endl;
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





