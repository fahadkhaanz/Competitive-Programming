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
        ll int a,b;
        cin>>a>>b;
        ll int aa=a,bb=b;
        string s;
        cin>>s;
        ll int n=s.size();
        for(auto i:s)
        {
            if(i=='0') a--;
            if(i=='1') b--;
        }
        ll int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]=='?' and s[j]=='?')
            {
                i++;
                j--;
                continue;
            }
            if(s[i]=='?')
            {
                if(s[j]=='0')
                {
                    if(a>0)
                    {
                        a--;
                        s[i]='0';
                    }
                    else
                    {
                        cout<<"-1\n";
                        return;
                    }
                }
                else
                {
                     if(b>0)
                    {
                        b--;
                        s[i]='1';
                    }
                    else
                    {
                        cout<<"-1\n";
                        return;
                    }
                }
            }
            else if(s[j]=='?')
            {
                if(s[i]=='0')
                {
                    if(a>0)
                    {
                        a--;
                        s[j]='0';
                    }
                    else
                    {
                        cout<<"-1\n";
                        return;
                    }
                }
                else
                {
                     if(b>0)
                    {
                        b--;
                        s[j]='1';
                    }
                    else
                    {
                        cout<<"-1\n";
                        return;
                    }
                }
            }
            i++;
            j--;

        }

        i=0;
        j=n-1;
        while(i<j)
        {
            if(s[i]=='?' and s[j]=='?')
            {
                if(a<2 and b<2)
                {
                    cout<<"-1\n";
                    return;
                }
                if(a>=2)
                {
                    s[i]='0';
                    s[j]='0';
                    a-=2;
                }
                else
                {
                    s[i]='1';
                    s[j]='1';
                    b-=2;
                }
            }
            i++;j--;
        }
        if(s[i]=='?')
        {
            if(a<1 and b<1)
            {
                cout<<"-1\n";
                return;
            }
            if(a>=1)
            {
                s[i]='0';
            }
            else
            {
                s[i]='1';
            }
        }
        i=0;
        j=n-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                cout<<"-1\n";
                return;
            }
            i++;
            j--;
        }
        ll int ca=0,cb=0;
        for(auto i:s)
        {
            if(i=='0') ca++;
            else if(i=='1') cb++;
        }
        if(ca!=aa||cb!=bb)
        {
            cout<<"-1\n";
            return;
        }
        cout<<s<<"\n";
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





