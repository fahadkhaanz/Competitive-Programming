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
void nextPermutation(vector<ll int> &A) {
    int i,j,small,big,temp;
    for(i=A.size()-1;i>0;i--)
    {
        if(A[i]>A[i-1])
            break;
    }
    if(i==0)
    {
        sort(A.begin(),A.end());
        return ;
    }
    small=i-1;
    big=i;
    temp=big;
    for(i=A.size()-1;i>big;i--)
    {
        if(A[i]>A[small] && A[i]<A[temp])
            temp=i;
    }
    int t=A[temp];
    A[temp]=A[small];
    A[small]=t;
    small++;
    sort(A.begin()+small,A.end());
}

void solve()
    { 
        ll int n,cost;
        cin>>n>>cost;
        vl ar(n),A(n);
        fo(i,n) A[i]=i+1;
        int f=1;
        for(int i=1;i<=n;i++) f=f*i;
        int kkkkk=f;
        while(kkkkk--)
        {   
           
            nextPermutation(A);

            ar=A;
            //  for(int i=0;i<n;i++) cout<<ar[i]<<" ";
            //  cout<<endl;
            //  continue;
            ll int ans=0;
            for(int i=0;i<n-1;i++)
        {   
            int jj=i; ll int min=ar[i];
            for(int j=i;j<n;j++)
            {    
               
                if(ar[j]<min)
                {
                    min=ar[j];
                    jj=j;
                }
            }
            // if(jj==-1) continue;
            // deb2(i,jj);
            reverse(ar.begin()+i,ar.begin()+jj+1);
            ans+=jj-i+1;
        }
        // deb(ans);
        if(ans==cost)
        {
             cout<<"Case #"<<tc++<<": ";
             for(int i=0;i<n;i++) cout<<A[i]<<" ";
             cout<<endl;
             return;
        }
       
        
    
        }
         cout<<"Case #"<<tc++<<": IMPOSSIBLE\n";
        
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





