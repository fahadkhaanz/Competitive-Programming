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
        vl br(45,0);
        vl ar(n);
        int k=1;
        fo(i,n) {cin>>ar[i];
        if((ar[i]==4||ar[i]==8||ar[i]==15||ar[i]==16||ar[i]==23||ar[i]==42) and br[ar[i]]==0) br[ar[i]]=i+1;
        }
        fo(i,n)
        {   
              if(ar[i]==4 and br[4]==0) br[4]=i+1;
              if(ar[i]==8 and br[4]>br[8]) br[8]=i+1; 
              if(ar[i]==15 and (br[8]>br[15]||br[4]>br[15])) br[15]=i+1;
              if(ar[i]==16 and (br[8]>br[16]||br[4]>br[16])||br[15]>br[16]) br[16]=i+1;
              if(ar[i]==23 and (br[8]>br[23]||br[4]>br[23]||br[15]>br[23]||br[16]>br[23])) br[23]=i+1;
              if(ar[i]==42 and (br[8]>br[42]||br[4]>br[42]||br[15]>br[42]||br[16]>br[42]||br[23]>br[42])) br[42]=i+1;
            
        }
        bool f=0;
        if((br[4]<br[8] and br[8]<br[15] and br[15]<br[16] and br[16]<br[23] and br[23]<br[42]))  f=1;
        if(br[4]==0||br[8]==0||br[15]==0||br[16]==0||br[23]==0||br[42]==0) f=0;
        if(f==0)
        {
            cout<<n;
            return;
        }
        cout<<n%6;
        
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





