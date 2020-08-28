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

ll int togglebit(ll int n) 
{ 
    if (n == 0) 
        return 1; 
  
    // Make a copy of n as we are 
    // going to change it. 
    ll int i = n; 
  
    // Below steps set bits after 
    // MSB (including MSB) 
  
    // Suppose n is 273 (binary 
    // is 100010001). It does following 
    // 100010001 | 010001000 = 110011001 
    n |= n >> 1; 
  
    // This makes sure 4 bits 
    // (From MSB and including MSB) 
    // are set. It does following 
    // 110011001 | 001100110 = 111111111 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    return i ^ n; 
} 
  
// Returns XNOR of num1 and num2 
ll int XNOR(ll int num1,ll int num2) 
{ 
    // if num2 is greater then 
    // we swap this number in num1 
    if (num1 < num2) 
        swap(num1, num2);  
    num1 = togglebit(num1); 
    
    return num1 ^ num2; 
} 
void solve()
    { 
        ll int a,b,n;
        cin>>a>>b>>n;
       
       
        ll int aa=a,bb=b,cc=a^b;
        ll int ccd=XNOR(a,b);
       // deb2(cc,ccd);        
        if(n%3==0)
        cout<<max(ccd,cc)<<"\n";
        else if(n%3==1)
        cout<<aa<<"\n";
        else 
        cout<<bb<<"\n";

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





