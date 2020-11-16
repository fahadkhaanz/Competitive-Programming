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
const ll int N = 3e5, M = N;
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
#define maxn 100010
// vector< vector< int > > rangeIndex(1000111);
vector< int > rangeIndex[maxn];
int last[maxn];
int fenwickTree[maxn];
int maxx[maxn];
int solutionVect[maxn];
int input[maxn];
// vector< vector < pair< int, int > > > queries(1000111);
vector < pair< int, int > > queries[maxn];

void createFenwickTree(int startingIndex, int endingIndex, int maximumValue)
{
    int i = startingIndex;
    while(i <= endingIndex)
    {
        fenwickTree[i] = max(fenwickTree[i], maximumValue);
        i += (i & -i);
        // cout << "ending index:" << fenwickTree[i] << endl;;
    }
}

void updateDAG(int index, int maxValue, int n)
{
    if(maxValue > maxx[index])
    {
        for(auto v: rangeIndex[index])
        {
            updateDAG(v, maxValue + 1, n);
        }
      
    }
    if(maxValue > maxx[index])
    {
        maxx[index] = maxValue;
        createFenwickTree(index, n, maxValue);
    }
}

int fenwickTreeRangeQuery(int endingIndex)
{
    int exists = endingIndex;
    int maxVal = 0;
    while(exists > 0)
    {
        int valueNow = fenwickTree[exists];
        if(valueNow > maxVal)
        {
            maxVal = valueNow;
        }
        exists -= (exists & -exists);
    }
    return maxVal;
}



void solve()
    { 
        int n, q,s;
        scanf("%d%d%d", &n, &q,&s);
        for(int i = 1; i <= n; i++)
        {
            int value;
            scanf("%d", &value);
            last[value] = i;
            input[i] = value;
            int prev = 0;
            for(int j = value - 1; j >= 1; j--)
            {
                if(last[j] > prev)
                {
                    prev = last[j];
                    rangeIndex[prev].push_back(i);
                }
            }
        }
      
        for(int i = 1; i <= q; i++)
        {
            int startIndex, endIndex;
            scanf("%d%d", &startIndex, &endIndex);
            int a=min(startIndex, endIndex),b=max(startIndex, endIndex);
            int l=
            queries[a].push_back(make_pair(b, i));
        }

        for(int i = n; i >= 1; i--)
        {
            updateDAG(i, 1, n);
            for(auto v:queries[i])
            {
                solutionVect[v.second] = fenwickTreeRangeQuery(v.first);
            }
           
         
        }
        for(int i = 1; i <= q; i++)
        {
            cout << solutionVect[i] << "\n";
        }
        

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





