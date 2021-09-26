//git pull --rebase origin master
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mep;
int bfs(vector<string> &s,vector<int> &vis,int n,int i)
{
    queue<pair<int,int>> q;
    q.push({i,1});

    int ans=1;
    while(!q.empty())
    {
        string cur=s[q.front().first];
        int i=q.front().first;
        int dis=q.front().second;
        q.pop();
        ans=max(ans,dis);
        if(vis[i]==1) continue;
        vis[i]=1;
 
         cout<<cur<<" ";
         mep.erase(cur);
        for(int ii=0;ii<n;ii++)
        {  
            if(vis[ii]==0)
            {
                string tmp=s[ii];
                int c=0;
                set<char> st;
                for(auto i:tmp) st.insert(i);
                for(auto i:cur) st.insert(i);
                c=max((int)st.size()-(int)cur.size(),(int)st.size()-(int)tmp.size());
            if(c<=1)
            {
                q.push({ii,dis+1});
               
            }
        }
     }

    }
    return ans;
}
void solve()
    { 
      int n;
      cin>>n;
      //deb(n);
      mep.clear();
      vector<string> s(n);
      for(int i=0;i<n;i++) 
      {
       string in;
       cin>>in;
       s[i]=in;
       // deb(s[i]);
      set<char> st;
      for(auto j:s[i]) st.insert(j);
      string t;
      for(auto j:st) t+=j;
      s[i]=t;
      mep[t]=i;
      //deb(s[i]);
      }
      vector<int> vis(n+1);
      int cnt=0;
      int ans=1;
      for(int i=0;i<n;i++)
      {   
         
          if(vis[i]==0)
          {  
               cnt++;
               cout<<"\n";
               ans=max(ans,bfs(s,vis,n,i));
          }
      }
      cout<<ans<<" "<<cnt<<"\n";
    }

int main() {

    int t;
    cin>>t;
    while (t--)
    {
         solve();
    }

    return 0;
}




