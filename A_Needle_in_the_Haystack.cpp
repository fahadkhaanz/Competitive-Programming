//git pull --rebase origin master
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for( int  i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define  ll long long
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
#define wi(t)  int  t;cin>>t;while(t--)
typedef pair< int ,  int >	pii;
typedef pair<ll,ll >	pl;
typedef vector< int >		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
 int  rng( int  lim) {
    uniform_int_distribution< int > uid(0,lim-1);
    return uid(rang);
}
 int  mpow( int  base,  int  exp); 
void ipgraph( int  n,  int  m);
void dfs( int  u,  int  par);

const  int  mod = 1000000007;
const  int  N = 3e5, M = N;
//=======================

vi adj[N];
vi vis(N);
  int  gcd(  int  a,   int  b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
 int  tc=1;
 int  rolling(string a)
{
     int  n=a.size();
     int  p=31;
     int  ans=0;
    for( int  i=0;i<n;i++)
    {
        ans=(ans+((a[i]-'a'+1)*mpow(p,i))%mod)%mod;
       
    
        
    }
    return ans;
}
 int  power( int  a ,  int  n)
{
	 int  result = 1;
 
	while(n)
	{
		if(n & 1) result = (result * a) % mod;
 
		n >>= 1;
		a = (a * a) % mod;
	}
 
	return result;
}

 vi dp(1000001);
 vi in(1000001);
void boom(string b)
{
     int  p = 31;
	 int  p_power = 1;
	in[0] = 1;
	dp[0] = (b[0] - 'a' + 1);
 
 
	for( int  i=1;i<b.size();i++)
	{
		char ch = b[i];
 
		p_power = (p_power * p) % mod;
		in[i] = power(p_power , mod - 2);
 
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
    
}
 int  ok( int  l, int  r)
{
     int  res=dp[r];
    if(l>0)
    res=(res-dp[l-1]+mod)%mod;
    
    return (res*in[l])%mod;

}
void solve()
    {   
         int  n;
         cin>>n;
       

    }

 int  main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
     int  input;
    while(cin>>input)
    {
        string a,b;
        cin>>a>>b;
        if(a.size()>b.size()) 
        {
            cout<<"\n";
            continue;
        }
         int  rolla=rolling(a);
        // deb(rolla);
        dp.clear();
        in.clear();
        boom(b);
         int  c=0;
         int  k=a.size()-1;
        bool f=0;
       
        for( int  i=0;i<=b.size()-a.size();i++)
        {   
            // deb(ok(i,i+k));
            if(ok(i,i+k)==rolla) 
            {
                cout<<i<<"\n";
                f=1;
            }
        }
      cout<<endl;

    }

    return 0;
}

 int  mpow( int  base,  int  exp) {
  base %= mod;
   int  result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph( int  n,  int  m){
     int  i, u, v;
    while(m--){
        cin>>u>>v;
    u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void dfs( int  u,  int  par){
    for( int  v:adj[u]){
        if (v == par) continue;
        dfs(v, u);
    }
}





