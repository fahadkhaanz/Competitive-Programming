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
        string s;
        cin>>s;
    //    ll int n;
       string n;
       if(s.size()==1 and (s[0]=='0' || s[0]=='8'))
       {
           cout<<"YES\n";
           cout<<s;
           return;
       }
       if(s.size()==2 and (s[0]=='0' || s[1]=='0'||stoi(s)%8==0||s[0]=='8'||s[1]=='8'))
       {
           cout<<"YES\n";
           if(s[1]=='0')
           cout<<"0\n";
           else if(s[0]=='8'||s[1]=='8') cout<<"8";
           else cout<<s;
           return;
       }
      if(s.size()==1||s.size()==2)
      {
          cout<<"NO\n";
          return;
      }
        if(s.find('0')!=string::npos)
       {   
           cout<<"YES\n";
           cout<<"0";
           return;
       }
       for(int i=0;i<s.size()-2;i++)
       {   
           n.push_back(s[i]);
           for(int j=i+1;j<s.size()-1;j++)
           {  
                n.push_back(s[j]);
              for(int k=j+1;k<s.size();k++)
              {
                  n.push_back(s[k]);
                  
                  if((stoi(n))%8==0)
                  {
                      cout<<"YES\n";
                      cout<<n;
                      return;
                  }
                  n.pop_back();

              }
               n.pop_back();
           }
            n.pop_back();
          
       }
       for(int i=0;i<s.size()-1;i++)
       {   
           n.push_back(s[i]);
           for(int j=i+1;j<s.size();j++)
           {  
                n.push_back(s[j]);
             
                  
                  if((stoi(n))%8==0)
                  {
                      cout<<"YES\n";
                      cout<<n;
                      return;
                  }
                 

           
               n.pop_back();
           }
            n.pop_back();
          
       }
       if(s.find('8')!=string::npos)
       {   
           cout<<"YES\n";
           cout<<"8";
           return;
       }
       if(s.find('0')!=string::npos)
       {   
           cout<<"YES\n";
           cout<<"0";
           return;
       }

        cout<<"NO\n";
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





