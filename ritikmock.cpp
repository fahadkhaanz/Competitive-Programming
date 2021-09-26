#include<bits/stdc++.h>
using namespace std;



int main() {
    string s;
    cin>>s;
    string ans;
    for(int i=0;i<s.size();i+=2)
    {   
        if(i+1<s.size())
        ans+=max(s[i],s[i+1]);
        else 
        ans+=s[i];
    }
    cout<<ans;


}