#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sortall(x) sort(all(x))
#define wi(t) int t;cin>>t;while(t--)
typedef vector<int>  vi;
int N=100005;
vi adj[100007];
vi adj2[100007];
vector<bool> vis(N);

vector<pair<ll int,ll int>> edges;
void dfs(ll int v,ll int p,ll int gggg) {
    vis[v] = true;
   
    for (int i : adj[v]) {
      if(!vis[i])
      {
          dfs(i,v,0);
      }
      else
      {
          if(i!=p)
          {
              edges.push_back({i,v});
          }
      }
    }
}
vi ans;
void dfs(ll int u,vector<ll int> &ar)
{
    ans.push_back(ar[u]);
    vis[u]=1;
    for(auto i:adj2[u])
    {
        if(!vis[i]) dfs(i,ar);
    }
}
void solve()
    { 
        int n,m;
        cin>>n>>m;
        vector<ll int> ar(n+1);
       
        for(int i=1;i<=n;i++)
        {
            cin>>ar[i];
            vis[i]=0;
            adj[i].clear();
            adj2[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            ll int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ans.clear();
        edges.clear();
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,0);
            }
        }
        for(auto e:edges)
        {  
           
            for(int i=1;i<=n;i++)
            {
                for(auto j:adj[i])
                {
                    if((i==e.first and j==e.second)||((j==e.first and i==e.second))) continue;
                    adj2[i].push_back(j);
                    adj2[j].push_back(i);
                }
            }
        }
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            dfs(i,ar);
        }
      
        int ok=ans.size();
        vector<ll int> pre(ok),sufi(ok);
        pre[0]=ans[0];
        sufi[ok-1]=ans[ok-1];
        for(int i=1;i<ok;i++)
        pre[i]=pre[i-1]+ans[i];
        for(int i=ok-2;i>=0;i--)
        {
            sufi[i]=sufi[i+1]+ans[i];
        }
      
        ll int diff=LONG_MAX;
        ll int aa,bb;
        for(int i=0;i<ok-2;i++)
        {
            if(abs(pre[i]-(sufi[i+2]))<diff)
            {
                diff=abs(pre[i]-(sufi[i+2]));
                aa=pre[i];
                bb=sufi[i+2];
            }
        }
        cout<<min(aa,bb)<<" "<<max(aa,bb)<<"\n";
    }

int main() {
   
    wi(t)
    {
      solve();
    }

    return 0;
}
