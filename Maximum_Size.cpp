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

ll int gcd(ll int a, ll int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int tc=1;
 vector<vector<char>> ar;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

 ll int n,m;
 vector<vector<int>> vis;
 bool isvalid(ll int x,int y)
 {
     if(x<0||x>=n||y<0||y>=m||vis[x][y]==1||ar[x][y]=='0') return false;
     return true;
 }
 ll int cc;
 void dfs2(int x,int y)
 {
     vis[x][y]=1;
     cc++;
     for(int i=0;i<4;i++)
     {
         if(isvalid(dx[i]+x,dy[i]+y))
         {
             dfs2(dx[i]+x,dy[i]+y);
         }
        
     }
 }
void solve()
    { 
       
        cin>>n>>m;
        vis.clear();
        vis.resize(n,vector<int>(m));
        ar.clear();
        ar.resize(n,vector<char>(m));
        fo(i,n)
        {
            fo(j,m) cin>>ar[i][j],vis[i][j]=0;
        }
         vl ans;
         fo(i,n)
        {
            fo(j,m) 
            {
                cc=0;
                if(vis[i][j]==0 and ar[i][j]=='1')
                {
                 dfs2(i,j);
                //  deb(cc);
                 ans.push_back(cc);
                }

            }
        }
        sortall(ans);
        ll int c=0;
        for(int i=ans.size()-2;i>=0;i-=2)
        c+=ans[i];
        cout<<c<<"\n";




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





