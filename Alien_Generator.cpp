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
bool check(ll int n,ll int g,ll int s)
{   
    ll int a=1,b=1,c=n;
    ll int d = b * b + 4 * a * c;
    double sqrt_val = sqrt((d));
 
    if (d > 0) {
        // cout << "Roots are real and different \n";
        ll int rt=(ll)((double)(-b + sqrt_val) / (2 * a));
        if((rt*(rt+1)/2==g+s)) 
        {return 1;}
        return 0;
    }
    else if (d == 0) {
        return 0;
      //  cout << -(double)b / (2 * a);
    }
    else // d < 0
    {
        return 0;
    }
}
bool isvalid(string s)
{
    int i=0,j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
        return 0;
        i++;
        j--;
    }
    return 1;
}
ll int  printAllSubstrings(string s, ll int n,string ss)
{
    /*
     * Fix start index in outer loop.
     * Reveal new character in inner loop till end of string.
     * Print till-now-formed string.
     */
    ll int c=0;
    for (int i = 0; i < n; i++)
    {
        char temp[n - i + 1];
        int gg=n - i + 1;
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';

             if(lexicographical_compare(temp, temp+gg, ss.begin(), ss.end()) and isvalid(temp)) c++;
        }
    }
    return c;
}
void solve()
    { 
       
        ll int n,k;
        cin>>n>>k;
        string ss;
        cin>>ss;
        string s;
        for(int i=0;i<k;i++)
        {
            s+=char(97+i);
        }
        ll int ans=printAllSubstrings(s,k,ss);
       
        cout<<"Case #"<<tc++<<": ";
        cout<<ans<<"\n";
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





