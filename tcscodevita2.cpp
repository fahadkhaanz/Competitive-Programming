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
vl ar(N+1);
vi ans;
ll int gcd(ll int a, ll int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int tc=1;
ll int sz,maxsum;
void dfs(int u)
{
    vis[u]=1;
    sz++;
    maxsum+=ar[u];
    ans.push_back(u);
    for(auto i:adj[u])
    {
        if(vis[i]==0) dfs(i);
    }

}
void solve()
    { 
        ll int n;
        cin>>n;
       
        for(int i=1;i<=n;i++) cin>>ar[i],vis[i]=0;
        ll int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }
        vi finalans;
        ll int fsum=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                ans.clear();
                sz=0;
                maxsum=0;
                dfs(i);
                if(maxsum>fsum)
                {
                    fsum=maxsum;
                    finalans=ans;
                }
                if(maxsum==fsum and finalans.size()>ans.size())
                {
                    finalans=ans;
                }
            }
        }
        sortall(finalans);
        for(auto i:finalans)
        {
            cout<<i<<" ";
        }

        
    }



    ll int mincostTickets(vector<ll int>& days, vector<ll int>& costs,vector<ll>& tic)
      {
         bool id[70002];
        ll int i, n = (ll)days.size(), dp[70002];
        if(n==1)
            return min({costs[0], costs[1], costs[2],costs[3],costs[4]}); // if we have only day 
        memset(id, 0, sizeof(id));
        
        for(auto day:days)
            id[day] = 1;
        
        for(int i=0;i<70002;i++)
            dp[i] = LONG_MAX;
        
        for(int i = 1+days[n-1];i<70002;i++)
            dp[i] = 0;
        
        for(int i=days[n-1];i>=0;i--){
            if(id[i])
                dp[i] = min({dp[i], costs[0]+dp[i+tic[0]], costs[1] + dp[i+tic[1]], costs[2] + dp[i+tic[2]],costs[3] + dp[i+tic[3]],costs[4] + dp[i+tic[4]]}); // buying the best plan
            else
                dp[i] = dp[i+1]; 
        }
        
        return dp[0]; 
    }
void c()
{
    vl tic(5);
    vl costs(5);
    cin>>tic[0]>>tic[1]>>tic[2]>>tic[3]>>tic[4];
    cin>>costs[0]>>costs[1]>>costs[2]>>costs[3]>>costs[4];
    int wk;
    cin>>wk;
   
    vl days;
    int k=1;
    while(wk--)
    {   
         string s;
        cin>>s;
        for(int i=0;i<(ll)s.size();i++)
        {
            if(s[i]=='X')
            days.push_back(k);
            k++;

        }
    }
    if(days.size()==0)
    {
        cout<<"0";
    }
    else
    cout<<mincostTickets(days,costs,tic);


}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // wi(t)
    {
      c();
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





