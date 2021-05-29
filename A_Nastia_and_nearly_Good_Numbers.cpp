#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll int x,y;
        cin>>x>>y;
        
        if(y==1)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        
        if(y==2)
        {
            cout<<x<<' '<<x*(y+1)<<' '<<y*x*2<<'\n'; 
            continue;
        }
        cout<<x<<" "<<x*(y-1)<<" "<<x*y<<"\n";
    }
}