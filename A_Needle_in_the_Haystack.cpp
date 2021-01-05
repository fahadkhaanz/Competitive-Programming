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
 ll int  rolling(string a)
{
     ll int  n=a.size();
     ll int  p=31;
     ll int  ans=0;
    //   ll int  p = 31;
	 ll int  p_power = 1;
     ans=(ans+((a[0]-'a'+1)*p_power)%mod)%mod;
    for(ll int  i=1;i<n;i++)
    {   
        p_power = (p_power * p) % mod;
        ans=(ans+((a[i]-'a'+1)*p_power)%mod)%mod;
    }
    return ans%mod;
}
 

 vl dp(1000001);
 vl in(1000001);
void boom(string b)
{
     ll int  p = 31;
	 ll int  p_power = 1;
	// in[0] = 1;
	 dp[0] = (b[0] - 'a' + 1);
     in[0]=1;
 
	for(ll int  i=1;i<b.size();i++)
	{
		char ch = b[i];
 
		p_power = (p_power * p) % mod;
		// in[i] = power(p_power , mod - 2);
        in[i]=p_power;
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
    
}
ll int  ok(ll  int  l, ll int  r)
{
   ll int  res=dp[r];
    if(l>0)
    res=(res-dp[l-1]+mod)%mod;
    
    return res%mod;

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
     cin>>input;
    while(input--)
    {
        string a,b;
        cin>>b>>a;
        if(a.size()>b.size()) 
        {
             cout<<"Not Found\n";
            continue;
        }
        ll int  rolla=rolling(a);
        // deb(rolla);
        dp.clear();
        in.clear();
        boom(b);
         ll int  c=0;
         ll int  k=a.size()-1;
        bool f=0;
        vector<ll> ans;
        for( ll int  i=0;i<=b.size()-a.size();i++)
        {   
            //  deb2(ok(i,i+k),(in[i]*rolla)%mod);
            if(ok(i,i+k)==(in[i]*rolla)%mod) 
            {
                ans.push_back(i+1);
                f=1;
            }
        }
        if(f==0)
        {
            cout<<"Not Found";
        }
        else
        {
            cout<<ans.size()<<"\n";
            for(auto i:ans) cout<<i<<" ";
        }
        
        cout<<"\n\n";

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





