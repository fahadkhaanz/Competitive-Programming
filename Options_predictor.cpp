#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter Number of Options\n";
    int n;
    cin>>n;
    cout<<"Enter Number of Statements\n";
    int m;
    cin>>m;
    char ar[n][m];
    for(int i=0;i<n;i++)
    {    
        cout<<"Enter Option "<<i+1<<"\n";
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
    string ans;
    vector<char> adj[m+5];
    for(int i=0;i<m;i++)
    {
        map<char,int> mp;
        char ch='#';
        int c=1;
        for(int j=0;j<n;j++)
        {
            mp[ar[j][i]]++;
        }
        for(auto ii:mp)
        {
            if(ii.second>c)
            {
                c=ii.second;
                ch=ii.first;
            }
        }
        int tc=0;
        if(c==2)
        {
            for(auto ii:mp)
            {
                if(ii.second==c) tc++;
            }
        }
        if(tc==2)
        {
            ch='#';
        }
        
        ans+=ch;
    }
    int ac=0;
    int op=0;
    map<int,vector<int> > cnt;
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<m;j++)
        {  
          if(ans[j]!='#' and ans[j]==ar[i][j]) c++;
        }
        if(c>=ac)
        {
            ac=c;
            cnt[ac].push_back(i);
            op=i;
        }
    }
    
    if(ac==0)
    {
        cout<<"Opps! It is not possible for me to find ans\n";
    }
     cout<<"Correct Option May be\n";
     for(auto i:cnt[ac])
        {
            cout<<"Option "<<i+1<<"\n";
        }
    



}