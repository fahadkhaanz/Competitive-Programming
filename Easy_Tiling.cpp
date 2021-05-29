#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
bool comp(pair<string, pair<int, int> > a,pair<string, pair<int, int> > b)
{
    if(a.second.second>b.second.second) return true;
    if(a.second.second==b.second.second)
    {
        if(a.first<b.first) return true;
        if(a.first==b.first) 
        {
            if(a.second.first<b.second.first) return true;
        }
    }
    return false;
}

int main(){
   int n;
   cin>>n;
    vector< pair<string, pair<int, int> > > ar(n);
    for(int i=0;i<n;i++)
    {
        cin>>ar[i].first>>ar[i].second.first>>ar[i].second.second;
    }
    sort(ar.begin(),ar.end(),comp);
    for(int i=0;i<n;i++)
    {
        cout<<ar[i].first<<" "<<ar[i].second.first<<" "<<ar[i].second.second<<"\n";
    }
return 0;
}
