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
ll int vlue=1e4;
ll int gcd(ll int a, ll int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int tc=1;
void A()
{
 
        
            ll int n;
            cin>>n;
            if(n==1)
            {
               cout<<('0');
               return;
            }
            ll int k=n;
            string ar="";
                 while(k>0)
            {
                if((int)k%2==0) ar+='0';
                else ar+='1';
                k=k/2;
            }
            string s=ar;
            ll int a=0,b=0,aa=0,bb=0;

            ll int ans=1;

            for(int i=0;i<ar.size();i++)
            {
                if(s[i]=='0')
                {
                    aa+=pow(2,i);
                    bb+=pow(2,i);
                }
            }

            for(int i=max((int)0,(int)ar.size()-2);i<ar.size();i++)
            {   a=aa;
                b=bb;
                for(int j=0;j<=i;j++)
                {
                    if(s[j]=='1') a+=pow(2,j);
                }
                for(int j=i+1;j<ar.size();j++)
                {
                    if(s[j]=='1') b+=pow(2,j);
                }
                ans=max(ans,a*b);

            }
            cout<<ans<<"\n";
        
}
bool isproper(int c,int d)
{   
    ll int cnt=0;
    for(int i=0;i<vlue;i++)
    {
        for(int j=0;j<vlue-1;j++)
        {
            if(c==d) cnt++;
        }
    }
    if(!cnt) return true;
    return false;
}
void B()
{
            int n;
            cin>>n;
            vl ar(n);
            bool f=1;
            int diff=0;
            for(int i=0;i<n;i++) 
            cin>>ar[i];
            sortall(ar);
            for(int i=0;i<n;i++)
            {
                if(ar[i]>(i+1))
                {
                    f=0;
                    break;
                }
                diff+=(i+1)-ar[i];
            }
            if(diff%2==0||f==0)
            {
                cout<<"Second"<<"\n";
            }
            else
            {
                cout<<"First"<<"\n";
            }
}

vl ar(N),br(N),cr(N),dr(N);
vl ans1,ans2;
ll int ans=INT_MIN;


bool isvalid(ll int x,int y)
{
    for(int i=0;i<ans1.size();i++)
    {
        if(ans1[i]<=y and ans2[i]>=x) return true;  
    }
    return false;
}
ll int solve(ll n,ll e,ll h,ll a,ll b,ll c)
    { 
        if(n<=0) return 0;
        ll int ans=1000000000000000;
        if(n<=e and n<=h) ans=min(ans,n*c);
        if(2*n<=e) ans=min(ans,n*a);
        if(3*n<=h) ans=min(ans,b*n);
        if((h-n)/2>=1 and (h-n)/2>=(n-e))
        {
            if((b-c)<0)
            {   
                ll int t=min(n-1,(h-n)/2);
                ans=min(ans,(b-c)*t+n*c);
            }
            else
            {    
                ll int t=max(1LL,(n-e));
                 ans=min(ans,(b-c)*t+n*c);
            }
        }
        if((e-n)>=1 and (e-n)>=(n-h))
        {
            if((a-c)<0)
            {   
               ll int t=min(n-1,(e-n));
                ans=min(ans,(a-c)*(t)+n*c);
            }
            else
            {    
                 ll int t=max(1LL,(n-h));
                 ans=min(ans,(a-c)*t+n*c);
            }
        }
        if(e/2>=1 and (e/2>=(3*n-h+2)/3))
        {
            if((a-b)<0)
            {    
                ll int t=min(n-1,e/2);
                ans=min(ans,(a-b)*t+n*b);
            }
            else
            {   
                 ll int t=max(1LL,((3*n-h+2)/3));
                ans=min(ans,(a-b)*t+n*b);
            }
        }
        if(n>=3 and e>=3 and h>=4)
        {
            ans=min(ans,a+b+c+solve(n-3,e-3,h-4,a,b,c));
        }
        
       return ans;
    }

void D()
{
    ll int n;
    cin>>n;
    vector<double> ar(n);
    vector<pair<double,double>> st;
    fo(i,n) cin>>ar[i];
    st.push_back({ar[0],(double)0});
    st.push_back({ar[1],(double)1});
    double  ans=(double)1;
    int k=2;
    for(double i=2;i<n;i++)
    {   
        while(k>=2)
        {
        double x=i,y=ar[i],top1x=st[k-1].S,top1y=st[k-1].F;
        double top2x=st[k-2].S,top2y=st[k-2].F;
        double dy=(y-top1y)/(x-top1x);
        double dx=(top1y-top2y)/(top1x-top2x);
        // deb2(dx,dy);
        if(dx>dy)
        {
            break;
        }
        else
        {
           k--;
           st.pop_back();
        }
        
        }
        st.push_back({ar[i],i});
        k++;
        ans=max(ans,st[k-1].S-st[k-2].S);
        
        


    }
    cout<<(ll)ans<<"\n";
    

}
void E()
{
    ll int n,m,x;
    cin>>n>>m>>x;
    int ar[n][m],br[n][m];
    fo(i,n)
    {
        fo(j,m) cin>>ar[i][j];
    }
     fo(i,n)
    {
        fo(j,m) cin>>br[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m-x;j++)
        {
            if(ar[i][j]!=br[i][j])
            {
                 int k=br[i][j]-ar[i][j];
                 for(int z=j;z<j+x;z++) ar[i][z]+=k;
            }
        }
    }
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<=n-x;j++)
        {
            if(ar[j][i]!=br[j][i])
            {
                int k=br[j][i]-ar[j][i];
                for(int z=j;z<j+x;z++) ar[z][i]+=k;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ar[i][j]!=br[i][j])
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";

    


}



ll int bfs(ll int x,ll int m,ll int y)
{
 ans1.push_back(x);
 ans2.push_back(x);
 ll int ans=INT_MIN;
 ll int cnt=0;
 if(x==y) return 0;
 while(ans==INT_MIN and ans1.size()!=0)
 {
  vl tmpans1,tmpans2;
  fo(i,m)
  {   
      if(isvalid(ar[i],br[i]) and vis[i]==0 and isproper(cr[i],dr[i]))
      {
          cout<<"ok\n";
          tmpans1.push_back(cr[i]);
          tmpans2.push_back(dr[i]);
          if(cr[i]<=y and dr[i]>=y) ans=cnt+1;vis[i]=1;
          deb(cnt);

      }
  }
  ans1=tmpans1;
  ans2=tmpans2;
  cnt++;

 }
 
 if(ans==INT_MIN) return -1;
 return ans;

}



void div3()
{
    string s;
    cin>>s;
    int ans=0,cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') cnt++;
        else
        {
            if(cnt>0) ans++;
            cnt=0;

        }
    }
    if(cnt>0) ans++;
    cout<<ans<<"\n";
}

void div3B()
{
   ll int n,h,x;
   cin>>n>>h>>x;
   vl ar(n);
   ll int mx=0;
   fo(i,n) cin>>ar[i],mx=max(ar[i],mx);
   if(mx+x>=h)
   {
       cout<<"YES\n";
   }
   else
   {
       cout<<"NO\n";
   }
}
// ll int ans=1e6;
void F()
{
    ll int n;
    cin>>n;
    vl ar(n);
     map<ll,ll> mep;
    fo(i,n) cin>>ar[i],mep[ar[i]]++;
    if(n==1) {cout<<"0\n";return;}
    ll int cnt=1;
    ll int ans=0;
 
    for(int i=1;i<n;i++)
    {
        if(ar[i]==ar[i-1]) {cnt++;continue;}
        ans+=(n-i)*cnt;
        cnt=1;
       
    }
    cout<<ans<<"\n";
    //  cout<<ans*(ans-1)/2<<"\n";
}


void challenge()
{
  ll int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++) 
  {
      int a,b;
      cin>>a>>b;
  }
  ll int ar[m][4];

  for(int i=0;i<m;i++)
  {
      
      cin>>ar[i][0]>>ar[i][1]>>ar[i][2]>>ar[i][3];
      if(ar[i][2]<ar[i][0])
      {   
            
            swap(ar[i][1],ar[i][3]);
            swap(ar[i][0],ar[i][2]);
         
      }

      if(i%2==1) 
      {
          cout<<(ans+1-ar[i][0])<<" "<<(ans-ar[i][1])<<"\n";
      }
      else
      {
          cout<<-ar[i][0]<<" "<<-ar[i][1]-1<<"\n";
      }
  }

//   for(int i=0;i<m;i++)
//   {
      
//      cout<<ar[i][0]<<ar[i][1]<<ar[i][2]<<ar[i][3]<<"\n";
// //   }

//   fo(i,m)
//   {  
      
//   }

}
ll int fac(ll int n)
{
    ll int f=1;
    for(int i=1;i<=n;i++) 
    {
        f=(f%mod*i%mod)%mod;
    }
    return f;
}
void topo()
{
    ll int n,k;
    cin>>n>>k;
    vl dp(n+1,0);
    fo(i,n-1) 
    {
        ll int a,b;
        cin>>a>>b;
        dp[a]++;
        dp[b]++;
    }
    map<ll,ll> mep;
    int in=0;
    ll int mx=0;
    for(ll int i=1;i<=n;i++)
    {    
        if(dp[i]>mx)
        {
            mx=dp[i];
            in=i;
        }
        
        // mep[in[i]]++;
    }

     for(ll int i=1;i<=n;i++)
    {    
        if(in==i) continue;
        
        mep[dp[i]]++;
    }
    ll int ans=0;
    for(auto i:mep)
    {
        ans=(ans%mod+fac(i.S)%mod);
        ans=ans%mod;
    }
    cout<<in<<" "<<ans<<"\n";


}



void dense()
{
  ll int n,m,x,y;
  cin>>n>>m>>x>>y;
  ans1.clear();
  ans2.clear();
  ar.clear();
  br.clear();
  cr.clear();
  dr.clear();
  fo(i,m) 
  {
      cin>>ar[i]>>br[i]>>cr[i]>>dr[i];
      vis[i]=0;
  }
  ll int ans=bfs(x,m,y);
  cout<<ans<<"\n";

}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

   wi(t)
    {  
        dense();
        // return //0;
        continue;
        // return 0;
        // continue;
        ll int n,e,h,a,b,c,tmp=0;
        cin>>n>>e>>h>>a>>b>>c;
        ll int ans=solve(n,e,h,a,b,c);
        if(ans==1000000000000000) 
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<ans<<"\n";
        }
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





