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
     int n,p;
     cin>>n>>p;
     string s;
     cin>>s;
     string tmp=s;
     ll int ans1=0,ans2=0;
     if(p>=n/2)
     {
         reverse(all(s));
         tmp=s;
         p=n-p+1;
     }
     ll int lll=-1,rr=-1;
     
         ll int cnt=0;
         for(int i=p-1;i<n/2;i++)
         {
               
               if(s[i]!=s[n-i-1])
               {
                    int r=(s[n-i-1]-'a');
                    int l=(s[i]-'a');
                //  deb2(s[i],s[n-i-1]);
                 int mn1='z'-s[n-i-1]+s[i]-'a'+1;
                 int mn2='z'-s[i]+s[n-i-1]-'a'+1;
                //  deb2(mn1,mn2);
                 s[i]=s[n-i-1];
                //  deb(min(abs(r-l),min(mn1,mn2)));
                 ans1+=min(abs(r-l),min(mn1,mn2));
                //  deb(ans1);
                 rr=i;
               }
                
           
             
         }
        //  cout<<"ok\n";
        //  s=tmp;
         cnt=0;
          for(int i=n/2-1;i>=0;i--)
         {
             if(s[i]==s[n-i-1])
            continue;
             else
             {
                
                 int r=(s[n-i-1]-'a');
                 int l=(s[i]-'a');
                //   deb2(s[i],s[n-i-1]);
                 int mn1='z'-s[n-i-1]+s[i]-'a'+1;
                 int mn2='z'-s[i]+s[n-i-1]-'a'+1;
                //  deb2(mn1,mn2);
                 s[i]=s[n-i-1];
                //  deb(min(abs(r-l),min(mn1,mn2)));
                 ans1+=min(abs(r-l),min(mn1,mn2));
                //  deb(ans1);
                lll=i;
             }
             
         }
         p--;
        if(lll==-1) lll=p;
        if(rr==-1) rr=p;
        // deb2(lll,rr);
       ans1+=rr-p+p-lll;
       ans1+=min(rr-p,p-lll);
       cout<<ans1;

     
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





