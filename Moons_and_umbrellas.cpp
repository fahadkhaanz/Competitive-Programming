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
         ll int ans=0;
         ll int x,y;
         string s;
         cin>>x>>y>>s;
         ll int n=s.size();
         if(x<0 and y<0)
         {
             if(s.size()>1 and s[0]=='?')
             {
                 if(s[1]=='C') s[0]='J';
                 else s[0]='C';
             }
               
         for(int i=1;i<n-1;i++)
         {
             if(s[i]!='?') continue;
             if(s[i+1]=='?'||s[i-1]==s[i+1])
             {   
                 if(s[i-1]=='C') s[i]='J';
                 else s[i]='C';
                
                 continue;
             }
            
                 s[i]=s[i-1];
                
            
         }
         if(s.size()>1 and s[n-1]=='?')
         {
             if(s[n-2]=='C') s[n-1]='J';
             else s[n-1]='C';
         }
         
         }
         else if(x>0 and y>0)
         {
             if(s.size()>1 and s[0]=='?')
         s[0]=s[1];
         for(int i=1;i<n-1;i++)
         {
             if(s[i]!='?') continue;
             if(s[i+1]=='?'||s[i-1]==s[i+1])
             {
                 s[i]=s[i-1];
                 continue;
             }
            
                 s[i]=s[i-1];
                
            
         }
         if(s.size()>1 and s[n-1]=='?')
         s[n-1]=s[n-2];
         }
         else
         {
                if(s[0]=='?' and s.size()>1)
                {
                    if(s[1]=='C')
                    {
                        if(y<x) s[1]='J';
                        else s[1]='C';
                    } 
                    else
                    {
                        if(x<y) s[1]='C';
                        else s[1]='J';
                    }
                }
                for(int i=1;i<n-1;i++)
                {
                     if(s[i]!='?') continue;
             if(s[i+1]=='?'||s[i-1]==s[i+1])
             {   
                 if(x+y>=0) 
                 s[i]=s[i-1];
                 else
                 {
                     if(s[i-1]=='C') s[i]='J';
                     else s[i]='C';
                 }
                 continue;
             }
            
                 s[i]=s[i-1];
                }



         }
         
         for(int i=1;i<n;i++)
         {
             if(s[i]=='C' and s[i-1]=='J') ans+=y;
             if(s[i]=='J' and s[i-1]=='C') ans+=x;
         }
         cout<<"Case #"<<tc++<<": "<<ans<<"\n";
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





