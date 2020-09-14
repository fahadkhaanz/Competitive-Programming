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

vi g[N];
int a[N];
ll int gcd(ll int a, ll int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int tc=1;
void solve(int k)
    {   
        int n;
        cin>>n;
       // priority_queue<unsigned long long int>q;
        unsigned ll int a=0,b=0;
        string s(n,0);
        for(int i=n;i>=1;i--)
        {   
            unsigned ll int p=pow(i,k);
           // deb(p);
            if(a==b||llabs((a+p)-b)<=llabs(a-(p+b)))
            {
                a=a+p;
                s[i-1]='1';
            }         // 25 16 9 4 1
            else 
            {
                b+=p;
                s[i-1]='0';
            }
           // deb2(a,b);
        }
         unsigned ll int aa=0,bb=0;
        string s1(n,0);
        for(int i=n;i>=1;i--)
        {   
            unsigned ll int p=pow(i,k);
           // deb(p);
            if(aa==bb||llabs((aa+p)-bb)<=llabs(aa-(p+bb)))
            {
                aa=aa+p;
                s1[i-1]='0';
            }         // 25 16 9 4 1
            else 
            {
                bb+=p;
                s1[i-1]='1';
            }
           // deb2(a,b);
        }
        if(llabs(a-b)<=llabs(bb-aa))
        {
            cout<<llabs(a-b)<<"\n";
            cout<<s<<"\n";
        }
        else
        {
            cout<<llabs(bb-aa)<<"\n";
            cout<<s1<<"\n";
        }
        
        
        return;

    }

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
   int k;
   cin>>k;
    wi(t)
    {
      solve(k);
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





