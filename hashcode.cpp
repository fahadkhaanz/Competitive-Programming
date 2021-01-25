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
        ifstream in; //Creating object for input stream
        ofstream out; //Creating object for output stream
        in.open("a_example.txt");    //open a file to read input
        out.open("output.txt"); //open a fil    
        ll int n,tm1,tm2,tm3;
        cin>>n>>tm1>>tm2>>tm3;
        map<string,queue<int>> mep;
        for(int i=0;i<n;i++)
        {
            vector<string> tmp;
            int k;
            cin>>k;
            while(k--)
            {
                string s;
                cin>>s;
                tmp.push_back(s);
            }
            sortall(tmp);
            string mn;
            for(auto j:tmp) 
            mn+=j;
            mep[mn].push(i);
        }
      
        vl ans[5];
        int sz=mep.size();
        // return;
         while(tm1>0 and sz>=2)
        {   
            int i=0;
            for(auto j:mep)
            {
                if(i==2) break;
                else
                {   
                   if(mep[j.first].empty())
                   {
                       sz--;
                   }
                   else
                   {
                       ans[2].push_back(mep[j.first].front());
                       mep[j.first].pop();
                       i++;
                   }
                   
                  
                }
                
            }
            tm1--;
        }
       
        while(tm2>0 and sz>=3)
        {   
            int i=0;
            for(auto j:mep)
            {
                if(i==3) break;
                else
                {  
                     if(mep[j.first].empty())
                   {
                       sz--;
                   }
                   else
                   {
                         ans[3].push_back(mep[j.first].front());
                         mep[j.first].pop();
                         i++;
                   }
                   
                   
                }
                
            }
            tm2--;
        }
         while(tm3>0 and sz>=4)
        {   
            int i=0;
            for(auto j:mep)
            {
                if(i==4) break;
                else
                {  
                   if(mep[j.first].empty())
                   {
                       sz--;
                   }
                   else
                   {
                         ans[4].push_back(mep[j.first].front());
                         mep[j.first].pop();
                         i++;
                   }
                   
                  
                }
                
            }
            tm3--;
        }
        int d=0;
        // deb(ans[2].size());
        // deb(ans[3].size());
        // deb(ans[4].size());
        d+=(ans[2].size()/2);
        d+=(ans[3].size()/3);
        d+=(ans[4].size()/4);// d++;
       
        cout<<d<<"\n";
        while(ans[2].size()%2!=0)
        {
            ans[2].pop_back();
        }
        if(ans[2].size()%2==0)
        {
            for(int i=0;i<ans[2].size();i++)
            {
                if(i%2==0)
                {
                    cout<<2<<" "<<ans[2][i]<<" ";

                }
                else
                {
                    cout<<ans[2][i]<<" ";
                }
                if((i+1)%2==0)
                cout<<endl;
                
            }
        }
     while(ans[3].size()%3!=0)
        {
            ans[3].pop_back();
        }
         if(ans[3].size()%3==0)
        {
            for(int i=0;i<ans[3].size();i++)
            {
                if(i%3==0)
                {
                    cout<<3<<" "<<ans[3][i]<<" ";

                }
                else
                {
                    cout<<ans[3][i]<<" ";
                }
                if((i+1)%3==0)
                cout<<endl;
                
            }
           
            // cout<<"\n";
        }
        while(ans[4].size()%4!=0)
        {
            ans[4].pop_back();
        }
         if(ans[4].size()%4==0)
        {
            for(int i=0;i<ans[4].size();i++)
            {
                if(i%4==0)
                {
                    cout<<4<<" "<<ans[4][i]<<" ";

                }
                else
                {
                    cout<<ans[4][i]<<" ";
                }
                if((i+1)%4==0)
                cout<<endl;
                
            }
           
            // cout<<"\n";
        }
        in.close();             //closing the input file
        out.close(); 




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





