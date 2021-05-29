#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll int n,r;
    cin>>n;
    string s;
    cin>>s;
    cin>>r;
    map<char,ll> mp;
    for(auto i:s) mp[i]++;
    char ch;
    ll int mx=0;
    for(auto i:mp)
    {
        if(i.second>mx)
        {
            mx=i.second;
            ch=i.first;
        }
    }
    vector<char> ar;
    sort(s.begin(),s.end());
    ll int md=INT_MAX;
    for(auto i:mp)
    {
        if(i.second==mx) ar.push_back(i.first);
    }
    for(auto a:ar)
    {
        ll int low=lower_bound(s.begin(),s.end(),a)-s.begin();
        ll int hig=upper_bound(s.begin(),s.end(),a)-s.begin();
        if(md<abs(low-n/2))
        {
            ch=a;
        }
        if(md<abs(hig-1-n/2))
        {
            ch=a;
        }

        md=min(md,abs(low-n/2));
        md=min(md,abs(hig-1-n/2));

    }
    ll int ans=0; 
    
    int i;
    int j; 
    for(int jj=0;jj<n;jj++)
    {
         if(s[jj]==ch)
         {
             i=jj-1;
             break;
         }
    }
    for(int jj=n-1;jj>=0;jj--)
    {
         if(s[jj]==ch)
         {
             j=jj+1;
             break;
         }
    }
    if(mx==1)
    {
       i=n/2-1;
       j=n/2+1; 
    }

    r--;
    while(i>=0 || j<n)
    {
        if(r<=0) break;
        if(i>=0)
        {
            ans+=abs(s[n/2]-s[i--]);
            r--;
        }
        
        if(r<=0) break;
        if(j<n)
        {
                ans+=abs(s[n/2]-s[j++]);
                 r--;
        }
        // cout<<abs(s[n/2]-s[j++])<<" ";
        
        if(r<=0) break;

    }  
    cout<<ans;
}

 