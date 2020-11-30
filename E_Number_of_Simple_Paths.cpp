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


void dfs(int u, vector<int> adj[], int* vis, int* inDeg,
         int* outDeg)
{
    // Mark the source as visited
    vis[u] = 1;
 
    // Mark in-degree as 1
    inDeg[u] = 1;
 
    // Traversing adjacent nodes
    for (auto v : adj[u]) 
    {
        // If not visited
        if (vis[v] == 0) 
        {
            // Mark out-degree as 1
            outDeg[u] = 1;
 
            // DFS Traversal on
            // adjacent vertex
            dfs(v, adj, vis, inDeg, outDeg);
        }
    }
}
 
// Function to return minimum number
// of edges required to make the graph
// strongly connected
int findMinimumEdges(int source[], int N, int M, int dest[])
{
    // For Adjacency List
    vector<int> adj[N + 1];
 
    // Create the Adjacency List
    for (int i = 0; i < M; i++) 
    {
        adj[i].push_back(dest[i]);
    }
 
    // Initialize the in-degree array
    int inDeg[N + 1] = { 0 };
 
    // Initialize the out-degree array
    int outDeg[N + 1] = { 0 };
 
    // Initialize the visited array
    int vis[N + 1] = { 0 };
 
    // Perform DFS to count in-degrees
    // and out-degreess
    dfs(1, adj, vis, inDeg, outDeg);
 
    // To store the result
    int minEdges = 0;
 
    // To store total count of in-degree
    // and out-degree
    int totalIndegree = 0;
    int totalOutdegree = 0;
 
    // Find total in-degree
    // and out-degree
    for (int i = 1; i <= N; i++) 
    {
        if (inDeg[i] == 1)
            totalIndegree++;
        if (outDeg[i] == 1)
            totalOutdegree++;
    }
 
    // Calculate the minimum
    // edges required
    minEdges = max(N - totalIndegree, N - totalOutdegree);
 
    // Return the minimum edges
    return minEdges;
}
 
// Driver Code
void solve()
    { 
        int n;
        cin>>n;
        int m=n;
        int source[n];//= { 1, 3, 1, 3, 5 };
    int destination[m];// = { 2, 2, 3, 5, 6 };
    for(int i=0;i<n;i++)
    {
        cin>>source[i];
        cin>>destination[i];
    }
    unsigned ll int f=1;
    for(int i=1;i<=n;i++)
    {
        f=(f%mod*i%mod)%mod;
    }
    cout <<findMinimumEdges(source, n, m, destination)<<"\n";
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





